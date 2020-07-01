using System;
using System.Diagnostics;

/*
Задание: Array139. Дано множество A из N точек с целочисленными координатами x, y. Порядок на координатной плоскости определим следующим образом:
(x1, y1) < (x2, y2), если либо x1 < x2, либо x1 = x2 и y1 < y2.
Расположить точки данного множества по возрастанию в соответствии с
указанным порядком.
*/

struct point
{
    public int x;
    public int y;

    public void rand()
    {
        Random rand = new Random();
        this.x = rand.Next(0, 10);
        this.y = rand.Next(0, 10);
    }
}

namespace C_____laba_1_1
{
    class Program
    {
        static void Main(string[] args)
        {
            point[] mas;
            Stopwatch SW = new Stopwatch();

            Console.Write("Введите размер массива:");
            int n = int.Parse(Console.ReadLine());

            mas = new point[n];
            int[][] mas2 = new int[n][];
            for (int i = 0; i < mas.Length; i++)
            {
                mas[i].rand();
                mas2[i] = new int[2];
                mas2[i][0] = mas[i].x;
                mas2[i][1] = mas[i].y;
            }

            //---------- 1 array ----------
            Console.WriteLine("Массив 1 ДО: ");
            for (int i = 0; i < mas.Length; i++) Console.Write("X: {0} Y: {1} \n", mas[i].x, mas[i].y);
            point sup;

            SW.Start();

            for (int i = 0; i < mas.Length; i++)
            {
                for (int j = 0; j < mas.Length - 1; j++)
                {
                    if ((mas[j].x > mas[j + 1].x) || ((mas[j].x == mas[j + 1].x) && (mas[j].y > mas[j + 1].y)))
                    {

                        //то меняем местами if (mas[i] > mas[j]
                        sup.x = mas[j].x;
                        sup.y = mas[j].y;

                        mas[j].x = mas[j + 1].x;
                        mas[j].y = mas[j + 1].y;

                        mas[j + 1].x = sup.x;
                        mas[j + 1].y = sup.y;
                    }
                }
            }

            SW.Stop();

            Console.WriteLine("Массив 1 ПОСЛЕ:");
            for (int i = 0; i < mas.Length; i++) Console.Write("X: {0} Y: {1} \n", mas[i].x, mas[i].y);
            Console.WriteLine("Tick 1 = " + SW.ElapsedTicks);

            //---------- 2 array ---------------
            Console.WriteLine("Massiv 2 do: ");
            for (int i = 0; i < n; i++) Console.Write("X: {0} Y: {1} \n", mas2[i][0], mas2[i][1]);

            SW.Start();

            int tmpTop;
            int tmpLow;

            for (int j = 0; j < n; j++)
            {
                for (int i = 0; i < n - 1; i++)
                {
                    if (mas2[i][0] > mas2[i + 1][0])
                    {

                        //то меняем местами if (mas[i] > mas[j]

                        tmpTop = mas2[i][0];
                        tmpLow = mas2[i][1];

                        mas2[i][0] = mas2[i + 1][0];
                        mas2[i][1] = mas2[i + 1][1];

                        mas2[i + 1][0] = tmpTop;
                        mas2[i + 1][1] = tmpLow;
                    }
                }
            }

            SW.Stop();

            Console.WriteLine("Mass 2 posle:");
            for (int i = 0; i < mas.Length; i++) Console.Write("X: {0} Y: {1} \n", mas2[i][0], mas2[i][1]);
            Console.WriteLine("Tick 2 = " + SW.ElapsedTicks);

            //----------------------------------

        }

    }

}
