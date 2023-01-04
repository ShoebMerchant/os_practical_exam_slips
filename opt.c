#include <stdio.h>
int main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10],
        flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    printf("Enter number of frames:");
    scanf("%d", &no_of_frames);
    printf("Enter number of pages:");
    scanf("%d", &no_of_pages);
    printf("Enter page reference string:");
    for (i = 0; i < no_of_pages; ++i)
    {
        scanf("%d", &pages[i]);
    }

    /**
     * Initialize the frame with zero
     */
    for (i = 0; i < no_of_frames; ++i)
    {
        frames[i] = 0;
    }

    /**
     * Prints a Frames
     */
    for (i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        /**
         * Search For the Page in the Frame
         * if found flag 1 and flag 2 are set to 1
         */
        for (j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
                flag1 = flag2 = 1;
                break;
            }
        }

        /**
         * Handles the initialization
         */
        if (flag1 == 0)
        {
            for (j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == 0)
                {
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0)
        {
            flag3 = 0;
            /**
             * Search for optimal page array after the current page
             * and store it in temp array
             */
            for (j = 0; j < no_of_frames; ++j)
            {
                temp[j] = 0;
                for (k = i + 1; k < no_of_pages; ++k)
                {
                    if (frames[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }

            /**
             * if page is not repeated (not optimal)
             */
            for (j = 0; j < no_of_frames; ++j)
            {
                if (temp[j] == 0)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if (flag3 == 0)
            {
                max = temp[0];
                pos = 0;
                for (j = 1; j < no_of_frames; ++j)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            faults++;
        }
        printf("\n");
        for (j = 0; j < no_of_frames; ++j)
        {
            printf("%d\t", frames[j]);
        }
    }
    printf("\n\nTotal Pages Faults =%d", faults);
    return 0;
}