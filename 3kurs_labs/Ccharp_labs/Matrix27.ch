using System;
using System.Diagnostics;

/*
 Задание: Matrix27. Дана матрица размера M × N. Найти максимальный среди минимальных элементов ее строк.
*/

namespace Ccharp_3
{
    class Program
    {
        static void Main(string[] args)
        {
            var jag1 = new int[10][];
            var jag2 = new int[10][];
            Random rand = new Random();
            for (int i = 0; i < 10; i++)
            {
                jag1[i] = new int[rand.Next(1, 10)];
                jag2[i] = jag1[i];
            }

            Console.WriteLine("First jag mass : ");
            for (int i = 0; i < 10; i++)
            {
                Console.Write(i + ") ");
                for (int j = 0; j < jag1[i].Length; j++)
                {
                    jag1[i][j] = rand.Next(1, 10);
                    jag2[i][j] = jag1[i][j];
                    Console.Write(" " + jag1[i][j]);
                }
                Console.Write('\n');
            }
            Stopwatch SW = new Stopwatch();

            //----------------------
            SW.Start();
            int max = -1;
            int min = int.MaxValue;
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < jag1[i].Length; j++)
                {
                    if (jag1[i][j] < min)
                    {
                        min = jag1[i][j];
                        Console.WriteLine("MIN na " + i + " is " + min);
                    }
                }
                if (min > max)
                {
                    max = min;
                }
            }
            SW.Stop();
            Console.WriteLine($"MAX is {max}");
            Console.WriteLine($"Tick {SW.ElapsedTicks}");

            //charp style
            Console.WriteLine("Second jag mass : ");
            for (int i = 0; i < 10; i++)
            {
                Console.Write(i + ") ");
                for (int j = 0; j < jag2[i].Length; j++)
                {
                    Console.Write(" " + jag2[i][j]);
                }
                Console.Write('\n');
            }
            max = -1;
            min = int.MaxValue;
            SW.Restart();

            for (int i = 0; i < 10; i++)
            {
                Array.Sort(jag2[i]);
            }

            for (int i = 0; i < 10; i++)
            {
                if (jag2[i][0] < min)
                {
                    min = jag2[i][0];
                }
                if (min > max)
                {
                    max = min;
                }
            }

            Console.WriteLine("MAX is " + max);
            Console.WriteLine($"Tick {SW.ElapsedTicks}");

            Console.ReadKey();
        }
    }
}
