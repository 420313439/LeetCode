#include <stdio.h>
#include <stdlib.h>
#include "twoSum.h"

int main(void)
{
    /* 初始化 */
    int numsSize = 4;
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    nums[0] = 2;
    nums[1] = 7;
    nums[2] = 11;
    nums[3] = 15;

    int target = 9;
    int *returnSize;


    int *ans = twoSum(nums, numsSize, target, returnSize);

    printf("%d %d", ans[0], ans[1]);

    free(nums);
    free(ans);

    return 0;
}