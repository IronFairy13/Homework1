cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(homework_1 VERSION ${PROJECT_VERSION})

option(WITH_GTEST "Whether to build GTest test" ON)

configure_file(version.h.in version.h)

add_executable(homework_cli main.cpp)
add_library(homework_1 lib.cpp)

set_target_properties(homework_cli homework_1 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(homework_1
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(homework_cli PRIVATE
    homework_1
)

if(WITH_GTEST)
    find_package(GTest REQUIRED)
    add_executable(test_version test_version.cpp)

    set_target_properties(test_version PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
    )

    target_link_libraries(test_version
        GTest::gtest
        GTest::gtest_main
        homework_1
    )
endif()

if (MSVC)
    target_compile_options(homework_cli PRIVATE
        /W4
    )
    target_compile_options(homework_1 PRIVATE
        /W4
    )
    if(WITH_GTEST)
        target_compile_options(test_version PRIVATE
            /W4
        )
    endif()
else ()
    target_compile_options(homework_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(homework_1 PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    if(WITH_GTEST)
        target_compile_options(test_version PRIVATE
            -Wall -Wextra -pedantic -Werror
        )
    endif()
endif()

install(TARGETS homework_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT savchenko.mn.dev@gmail.com)
include(CPack)

if(WITH_GTEST)
    enable_testing()
    add_test(NAME test_version COMMAND test_version)
endif()
