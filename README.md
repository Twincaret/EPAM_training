## EPAM_training
**C++**

<details>
  <summary>Лаб_тема 1</summary>

  ***

  ## &#9745;  Практическое задание №1 

  * Определить комбинированный (структурный) тип, содержащий информацию о студенте: фамилия, имя, массив из 3-х оценок.

      * Определить динамический массив структур, состоящий из `N` элементов  
  (`N >= 5`, вводится с клавиатуры).

      * Выполнить ввод элементов в массив структур.

      * Вывести исходный массив структур на консоль, разработав функцию для форматного вывода элементов массива.

      * Разработать функцию для сортировки массива структур:
      ` a.` четные варианты - по возрастанию, нечетные - по убыванию;
      ` b.` в зависимости от остатка деления числа букв в вашей фамилии на `4` выбрать признак для сортировки и разработать функцию для его вычисления:

    | Остаток    | Условие для функции сортировки
    |:--------:  |:--------------------------------- |
    |  `0`       |  средний балл по 3-м предметам    |
    |  `1`       |  наибольший балл из 3-х предметов |
    |  `2`       |  наименьший балл из 3-х предметов |
    |  `3`       |  суммарный балл по 3-м предметам  |

      * Вывести изменённый массив структур на консоль, используя созданную в п.4 функцию. 

      * Освободить динамически выделенную память под массив структур.

  ***

  ## &#9745;  Практическое задание №2 

  * Разработать класс "строка". Методы класса: конструктор, деструктор и метод выполняющий задание в соответствии с вариантом. 

      * Дана строка символов. Заменить в ней каждую букву 'а' на последнюю букву последовательности, подсчитать количество таких замен.

  ***

  ## &#9745;  Практическое задание №3 

  * Разработать класс "вектор" (одномерный динамический массив). Методы класса: конструкторы, деструктор и методы преобразования массива в соответствии с вариантом. 

      * Ввести 2 массива по 10 элементов, используя различные конструкторы.

      * Один из массивов отсортировать (четные варианты – по убыванию, нечетные – по возрастанию), найти минимальное, среднее и максимальное значение массива. 

      * Для второго массива выполнить задание по варианту

  ***

  ## &#9745;  Практическое задание №4 

  * Создать базовый класс по варианту, содержащий 2 или более полей, и определить в нем конструктор, деструктор и метод вывода на экран значений полей класса. 

      * Разработать производные классы, в которые добавить минимум 1 поле и собственные методы (конструктор, деструктор, метод вывода на экран значений полей класса и метод, реализующий задание по варианту). 

      * Создать объекты разработанных классов и проверить работу реализованных в них методов. 

    | Базовый класс        | Производные классы                    | Метод                           |
    |:------------------:  |:------------------------------------: |:------------------------------: |
    | Грузоперевозчик      | Самолет, Поезд, Автомобиль            | Общая стоимость грузоперевозки  |

  ***

  ## &#9745;  Практическое задание №5 

  * Разработать класс "массив" (двумерный динамический массив). Методы класса: конструктор (выполняет ввод размерности массива, динамическое выделение памяти и ввод элементов массива), деструктор (освобождает динамически выделенную под массив память), метод печати (выполняет форматный вывод элементов массива в виде таблицы) и friend-метод, выполняющий решение задачи по варианту (если задачу решить нельзя, то сообщить об этом).

  ***

</details>

<details>
  <summary>Лямбда-контейнеры</summary>

  ***

  ### ТЕМА: Лямбды  

  ## &#9745;  Задание №1  

   * Создать лямбда-выражение для вывода элементов вектора.

   * Создать лямбда-выражение для подсчета количества перестановок при выполнении сортировки элементов вектора.

   * Создать лямбда-выражение для поиска вхождения подстроки, задаваемой пользователем, в строку.

  ## &#9745;  Задание №2  

   * Выполнить генерацию вектора из `N` последовательных элементов (например, `0 1 2 3 4`)

   * Сформировать новый вектор по следующему правилу: отбросить слева `k` первых элементов и добавить `k` последовательных элементов в конец вектора (например, `k = 2`, новый вектор `2 3 4 5 6`)


  ***


  ### ТЕМА: Стандартные контейнеры  

  ## &#9745;  Задание №1  
  
   * Создайте класс `employee`, который содержит имя (объект класса `string`) и номер (типа `long`) служащего. Включите в него метод `getdata()`, предназначенный для получения данных от пользователя и помещения их в объект, и метод `putdata()`, для вывода данных.  
     Напишите функцию `main()`, использующую этот класс. Создать массив типа `employee`, а затем предложить пользователю ввести данные до 100 служащих,  вывести данные всех служащих.  

  ## &#9745;  Задание №2  
  
   * Создать  программу, которая позволяет пользователю вводить целые числа, а затем сохранять их в массиве типа `int`. Программа должна вызвать пользовательскую  функцию, а затем выводить наибольший элемент и его индекс.  

  ## &#9745;  Задание №3  
  
   * Создать пользовательскую функцию `maxint()`, которая, обрабатывая элементы массива один за другим, находит наибольший. Функция должна принимать в качестве аргумента адрес массива и  количество элементов в нем, а возвращать индекс наибольшего элемента.  
 
  ## &#9744;  Задание №4  
  
   * В игре бридж каждому из игроков раздают `13` карт, таким образом, колода расходуется полностью. Программа должна позволить перемешать колоду  так, чтобы после перемешивания колоды она делилась на четыре части по `13` карт каждая. Каждая из четырех групп карт затем должна быть выведена. `*****`  

  ## &#9744;  Задание №5  
  
   * Разработать  программу для создания/использования встроенного типа для денежных значений, такого, как `$173 698 001.32` `*****`

  ***

</details>

<details>
  <summary>Работа с текстовыми файлами</summary>

  ***

  ## &#9745;  Практическое задание 

  * Сформировать массив, каждый элемент которого имеет следующую структуру служащий: ФИО, число рождения,  месяц рождения, год рождения, пол.  
  Вывести на экран сообщение пользователю вида:  
  
>   Выберите действие:  
> `1` загрузить данные из файла  
> `2` ввести данные  
> `3` добавление данных  
> `4` сортировка базы данных по алфавиту (по фамилии)  
> `5` сортировка базы данных по возрасту  
> `6` вывод: список людей, родившихся в заданном месяце  
> `7` вывод: фамилию самого старшего мужчины  
> `8` вывод: все фамилии, начинающиеся с заданной буквы  
> `0` выход из программы  
>   Ваш выбор___  

  ***

</details>

<details>
  <summary>Контейнерные классы</summary>

  ***

  ## &#9745;  Практическое задание 

  * Создать контейнерный  целочисленный класс-массив (или любой собственный класс-например, кинофильмов), реализуя функционал контейнеров в языке С++

      * Должен отслеживать два значения: данные и свою длину, использовать указатель для хранения данных.

      * Конструктор для создания пустого массива.

      * Конструктор для создания массива заданного размера.

      * Функция для очистки массива.

      * Деструктор. 

      * Должен иметь доступ к элементам массива (перегрузка `[]`). Контроль корректности индекса.

      * Функция доступа для возврата длины массива.

      * Функция для изменения размера массива.

      * Функция для добавления/удаления элемента. 

  ***

</details>

<details>
  <summary>Управление ресурсами</summary>

  ***

  ## &#9745;  Практическое задание 

  * Определить комбинированный (структурный) тип, содержащий информацию о студенте: фио, возраст, курс, группа. Разработать необходимые конструкторы, деструктор, оператор перегрузки.

      * Инициализировать список, хранящий данные структурного типа.

      * Разработать функтор сравнения, который позволит выбрать способ сравнения записей в массиве (по фио либо другому полю).

      * Создать вектор элементов структурного типа, поместив в контейнер не объект, а указатель на него (для снижения вычислительных затрат на манипуляции с ним), заполнить элементы вектора.

      * Выберите поле сортировки и отсортируйте вектор.

      * Очистить вектор.

      * Проверить программу на утечку памяти (вызовы конструктора/деструктора).

  ***

</details>

<details>
  <summary>Принципы SOLID</summary>

  ***

  ## &#9745;  Практическое задание 

  * Абстрактный класс `Shape`, который умеет вычислить свою площадь, периметр и т.п. (если умеете ­– то нарисовать).

      * Сделать несколько наследников от этого класса (круг, квадрат, прямоугольник). 

      * Написать общий код, который бы работал обобщённо с геометрическими фигурами. Например, считал бы суммарную площадь, отрисовывал бы их и т.п.

      * Конечная цель – убедиться, что если пользоваться интерфейсом, то можно писать обобщённый код, который может работать с разными реализациями.

  ***

</details>
