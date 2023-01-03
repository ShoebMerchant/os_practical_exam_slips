#include <stdio.h>
#define MAX 20

int frame[MAX], reference[MAX], memory[MAX][MAX], faults, no_of_refs, no_of_frames, position;

void accept()
{
    printf("Enter No. of Frames : ");
    scanf("%d", &no_of_frames);

    printf("Enter No. of references : ");
    scanf("%d", &no_of_refs);

    printf("Enter references : \n");
    for (int i = 0; i < no_of_refs; i++)
    {
        printf("[%d] = ", i);
        scanf("%d", &reference[i]);
    }
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

int display()
{
    for (size_t i = 0; i < no_of_refs; i++)
    {
        printf("%d ", reference[i]);
    }
    printf("\n");

    for (size_t i = 0; i < no_of_frames; i++)
    {
        for (size_t j = 0; j < no_of_refs; j++)
        {
            if (memory[i][j])
                printf("%d\t", memory[i][j]);
            else
                printf("\t");
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", faults);
}

void fifo()
{
    for (size_t i = 0; i < no_of_refs; i++)
    {
        if (search(reference[i]) == -1)
        {
            /**
             * If page no is not found
             * place it on the frame
             */
            frame[position] = reference[i];

            /**
             * Adjust the position after
             * the page no is set
             */
            position = (position + 1) % no_of_frames;

            faults++;

            for (size_t j = 0; j < no_of_frames; j++)
            {
                memory[j][i] = frame[j];
            }
        }
    }
}

int main()
{
    accept();
    fifo();
    display();
}