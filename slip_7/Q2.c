/**
 * Write the simulation program to implement demand
 * paging and show the page scheduling and total number
 * of page faults for the following
 * given page reference string.
 * Give input n as the number of memory frames.
 * Reference String:
 * 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2
 * i. Implement LRU
 */

#include <stdio.h>
#define MAX 20

int frame[MAX], ref[MAX], mem[MAX][MAX], faults,
    position, no_of_refs, no_of_frames, time[MAX];

void accept()
{
    int i;

    printf("Enter no.of frames:");
    scanf("%d", &no_of_frames);

    printf("Enter no.of references:");
    scanf("%d", &no_of_refs);

    printf("Enter reference string:\n");
    for (i = 0; i < no_of_refs; i++)
    {
        printf("[%d]=", i);
        scanf("%d", &ref[i]);
    }
}

void disp()
{

    for (int i = 0; i < no_of_refs; i++)
        printf("%d ,", ref[i]);

    printf("\n\n");

    for (int i = 0; i < no_of_frames; i++)
    {
        for (int j = 0; j < no_of_refs; j++)
        {
            if (mem[i][j] != -1)
                printf("%d\t", mem[i][j]);
            else
                printf("\t");
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", faults);
}

int search(int page_no)
{
    for (int i = 0; i < no_of_frames; i++)
    {
        if (frame[i] == page_no)
            return i;
    }
    return -1;
}

int get_lru()
{
    int min_i, min = 9999;
    for (int i = 0; i < no_of_frames; i++)
    {
        if (time[i] < min)
        {
            min = time[i];
            min_i = i;
        }
    }
    return min_i;
}

void lru()
{
    for (size_t i = 0; i < no_of_frames; i++)
    {
        frame[i] = -1;
    }

    int i;
    for (i = 0; i < no_of_refs && position < no_of_frames; i++)
    {
        int k = search(ref[i]);
        if (k == -1)
        {
            frame[position] = ref[i];
            time[position] = i;
            position++;
            faults++;

            for (int j = 0; j < no_of_frames; j++)
                mem[j][i] = frame[j];
        }
        else
            time[k] = i;
    }

    for (; i < no_of_refs; i++)
    {
        int k = search(ref[i]);
        if (k == -1)
        {
            if (i == 4)
                printf("Shouldnt reach here\n");
            position = get_lru();
            frame[position] = ref[i];
            time[position] = i;
            faults++;
            for (int j = 0; j < no_of_frames; j++)
                mem[j][i] = frame[j];
        }
        else
        {
            time[k] = i;
            for (int j = 0; j < no_of_frames; j++)
                mem[j][i] = frame[j];
        }
    }
}

int main()
{
    accept();
    lru();
    disp();

    return 0;
}