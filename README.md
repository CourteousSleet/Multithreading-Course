# Задачи из курса по многопоточному программированию (stepik.org)

## Задачи

### 1.Задача на сигналы.
Создайте процесс (сохраните его PID в /home/box/pid),
устойчивый к сигналам SIGTERM и SIGINT (неубиваемый).
    
    solution_executor = std::make_unique<IgnoringProcess>();

### 2. Задача на зомби.
Создайте два процесса - родитель и потомок (сохраните
их PIDы в /home/box/pid_parent и /home/box/pid_child). Потомок должен убиваться
по SIGTERM. При убийстве потомка не должно остаться процессов-зомби.

    solution_executor = std::make_unique<ZombieProcess>();

### 3. Задача на безымянные каналы.

Пусть у нас есть длинная команда вида:

    who | sort | uniq -c | sort -nk1

Надо ее прочитать из STDIN, выполнить и STDOUT записать в файл /home/box/result.out
Вы должны создать Makefile в домашнем каталоге.

Тестовая система выполнит make. Она ожидает, что появится файл, исполняемый файл -
/home/box/shell. После чего она исполнит его несколько раз, подавая
на STDIN разные строчки и проверяя result.out.
      
    solution_executor = std::make_unique<UnnamedPipesProcess>();

### 4. Задача на именованные каналы.
Напишите программу, которая создает два именованных канала - /home/box/in.fifo и /home/box/out.fifo

Пусть программа читает in.fifo и все прочитанное записывает в out.fifo.

    solution_executor = std::make_unique<NamedChannels>();

### 5. Тренировочная задача.
Создайте пару сокетов, соединяющую два процесса (файл с исходниками должен быть
один и находиться в /home/box/work.cpp). Процесс должен быть запущен.

[Не оценивается] Потренируйтесь передавать дескрипторы через эту пару сокетов.

    solution_executor = std::make_unique<SocketPair>();