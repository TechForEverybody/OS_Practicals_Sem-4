#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    int n;
    printf("\nEnter the number of processes : ");
    scanf("%d", &n);
    int burst_time[10], arrival_time[10], waiting_time[10], turnarround_time[10], sorted_arrival[10], increasing_time = 0,average_waiting_time=0,average_turnaround_time=0;
    printf("\nEnter the arrival time of processes\n");
    for (int i = 0; i < n; i++)
    {
        printf("enter the arrival time of processs %d :", i + 1);
        scanf("%d", &arrival_time[i]);
    }
    printf("\nEnter the burst time of processes\n");
    for (int i = 0; i < n; i++)
    {
        printf("enter the burst time of processs %d :", i + 1);
        scanf("%d", &burst_time[i]);
    }
    printf("\nThe tabular format of the problem is");
    printf("\nprocess  burst_time  arrival_time");
    for (int i = 0; i < n; i++)
    {
        printf("\n%7d  %10d  %12d", i, burst_time[i], arrival_time[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sorted_arrival[i] = arrival_time[i];
    }
    int key, j, temp;
    for (int i = 1; i < n; i++)
    {
        key = sorted_arrival[i];
        j = i - 1;
        while (key < sorted_arrival[j] && j >= 0)
        {
            sorted_arrival[j + 1] = sorted_arrival[j];
            j--;
        }
        sorted_arrival[j + 1] = key;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (sorted_arrival[i] == arrival_time[j])
            {
                waiting_time[j] = increasing_time - arrival_time[j];
                increasing_time = increasing_time + burst_time[j];
                arrival_time[j] = -1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        turnarround_time[i] = waiting_time[i] + burst_time[i];
    }
    printf("\n\nprocess  waiting_time  turnaround_time");
    for (int i = 0; i < n; i++)
    {
        printf("\n%7d  %12d  %15d", i, waiting_time[i], turnarround_time[i]);
    }
    for (int i = 0; i < n; i++)
    {
        average_waiting_time=average_waiting_time+waiting_time[i];
        average_turnaround_time=average_turnaround_time+turnarround_time[i];
    }
    printf("\nAverage Waiting Time is : %f",1.0*average_waiting_time/n);
    printf("\nAverage TurnAround Time : %f",1.0*average_turnaround_time/n);
    getch();
}