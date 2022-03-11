#include <cstdint>

#include <string>
using std::string;

#include <iostream>
using std::cout, std::cin;

#include <memory>
using std::unique_ptr;

#include "headers/IgnoringProcess.hpp"
#include "headers/ZombieProcess.hpp"
#include "headers/UnnamedPipesProcess.hpp"

int main() {

  uint_fast8_t option{};
  unique_ptr<IProcess> solution_executor{};

  cout << "Выберите номер задачи, решение которой нужно продемонстрировать: 1 - 5\n";
  cin >> option;
  switch (option) {
    case '1':
      cout << "1. Задача на сигналы.\n"
              "\n"
              "Создайте процесс \n(сохраните его PID в /home/box/pid), "
              "устойчивый к сигналам SIGTERM и SIGINT (неубиваемый).\n";
      solution_executor = std::make_unique<IgnoringProcess>();
      break;

    case '2':
      cout << "2. Задача на зомби.\n"
              "Создайте два процесса - \nродитель и потомок (сохраните "
              "их PIDы в /home/box/pid_parent и /home/box/pid_child).\nПотомок должен убиваться "
              "по SIGTERM. При убийстве потомка не должно остаться процессов-зомби.\n";
      solution_executor = std::make_unique<ZombieProcess>();
      break;

    case '3':
      cout << "3. Задача на безымянные каналы.\n"
              "\n"
              "Пусть у нас есть длинная команда вида:\n"
              "\n"
              "who | sort | uniq -c | sort -nk1\n"
              "Надо ее прочитать из STDIN, выполнить и STDOUT записать в файл /home/box/result.out\n"
              "\n"
              "Вы должны создать Makefile в домашнем каталоге.\n"
              "\n"
              "Тестовая система выполнит make. Она ожидает, что появится файл исполняемый файл - "
              "/home/box/shell. После чего она исполнит его несколько раз, подавая на STDIN разные строчки и проверяя result.out.\n";
      solution_executor = std::make_unique<UnnamedPipesProcess>();
      break;

    case '4':
      cout << "4. Задача на именованные каналы.\n"
              "\n"
              "Напишите программу, которая создает два именованных канала - /home/box/in.fifo и /home/box/out.fifo\n"
              "\n"
              "Пусть программа читает in.fifo и все прочитанное записывает в out.fifo.\n";
      solution_executor = std::make_unique<IgnoringProcess>();

      break;

    case '5':
      cout << "5. Тренировочная задача.\n"
              "\n"
              "Создайте пару сокетов, соединяющую два процесса (файл с исходниками должен быть "
              "один и находиться в /home/box/work.cpp). Процесс должен быть запущен.\n"
              "\n"
              "[Не оценивается] Потренируйтесь передавать дескрипторы через эту пару сокетов.\n";
      solution_executor = std::make_unique<IgnoringProcess>();
      break;

    default:
      cout << "Такого номера нет\n";
      return -1;
  }

  cout << "Запускаем\n";
  solution_executor->Execute();
  cout << "Завершено успешно5\n";
  return 0;
}
