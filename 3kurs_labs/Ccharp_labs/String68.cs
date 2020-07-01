using System;
using System.Diagnostics;
using System.Text;

/*
 Задание: String68. Дана строка, содержащая цифры и строчные латинские буквы.
Если буквы в строке упорядочены по алфавиту, то вывести 0; в противном случае
 вывести номер первого символа строки, нарушающего алфавитный порядок.
*/

public class Program

{
    public static int Main(string[] args)
    {
        Console.Write("Введите строку : ");
        string str = Console.ReadLine();

        Stopwatch SW = new Stopwatch();
        SW.Start();
        int tmp = 0;
        for (var i = 0; i < str.Length - 1; i++)
        {
            if (str[i + 1] < str[i])
            {
                Console.Write("Элемент \"{0}\", позиция {1} \n", str[i], i);
            }
            else
            {
                tmp++;
            }
        }

        if (tmp == str.Length - 1)
        {
            Console.WriteLine(" 0 ");//если строка в алфавитном порядке
        }

        SW.Stop();
        Console.WriteLine("С++ -> " + SW.ElapsedTicks);

        //# style ---------------------------
        StringBuilder sb = new StringBuilder(str);
        SW.Start();
        tmp = 0;
        for (var i = 0; i < sb.Length - 1; i++)
        {
            if (sb[i + 1] < sb[i])
            {
                Console.Write("Элемент \"{0}\", позиция {1} \n", sb[i], i);
            }
            else
            {
                tmp++;
            }
        }
        if (tmp == sb.Length - 1)
        {
            Console.WriteLine(" 0 ");//если строка в алфавитном порядке
        }
        SW.Stop();
        Console.WriteLine("С#  StringBuilder -> " + SW.ElapsedTicks);

        return 0;

    }

}
