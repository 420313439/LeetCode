/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

/* 暴力破解法：遍历每一个i和j，直到找到num[i] + num[j] == target为止 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int *ans = (int *)malloc(sizeof(int) * 2);
                ans[0] = i;
                ans[1] = j;
                *returnSize = 2;

                return ans;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}