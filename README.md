1. Сборка и публикация пакета
Создаем сборочную ферму, которая будет обеспечивать автоматическую сборку наших проектов и запуск тестов с помощью GitHub Actions.



Что нужно сделать?
Написать программу, выводящую на консоль две строки:



build N
Hello, World!
Где вместо N должен выводится текущий номер сборки. Запустить на этапе сборки тесты, проверяющие валидность номера версии. Выложить исходные тексты в репозиторий на github.

Настроить Github Actions workflow для автоматической сборки проекта на каждый коммит. Так же настроить автоматический выпуск релиза либо на каждый коммит, либо по созданию тэга. В связи с недавними обновлениями политики безопасности для работы с репозиторием из консоли потребуется создать access token.

Варианты организации исходников по самостоятельным работам:

отдельный репозиторий под каждую работу

отдельная ветка в одном и том же репозитории под каждую работу

отдельная директория в одной и той же ветке одного и того же репозитория



Самоконтроль
версия пакета увеличивается от сборки к сборке

актуальная версия выводится в приветственном сообщении

пакет helloworld, содержащий исполняемый файл helloworld, опубликован в качестве релиза в репозитории



Проверка
Задание считается выполненным успешно, если после установки скаченного из релиза пакета:



apt update && apt install -y helloworld-0.0.X-Linux.deb
(вместо X – номер билда), запуска бинарного файла:
helloworld_cli
появилось сообщение:
Version: X
Hello, World!
(вместо X – опять же, номер билда).






Дополнительное упражнение

Добавить unit-тест, который будет полностью повторяет предложенный в материалах вебинара тест test_version.cpp, но сделать его с использованием GoogleTest framework. GoogleTest при этом либо подключить к репозиторию в качестве submodule и собрать вместе с тестом, либо установить на этапе подготовке к сборке через Github Actions.

