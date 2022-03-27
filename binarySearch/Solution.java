import java.util.Arrays;
import static java.lang.Math.ceil;

public class Solution {

    public static void setRange(int[] array, int firstIndex, int lastIndex) {
        array[0] = firstIndex;
        array[1] = lastIndex;
    }

    public static int rangeMean(int[] array) {
        return (int) ceil((array[0] + array[1]) / 2);
    }

    // Overload
    public static int search(int[] nums, int target, int[] range) {
        int[] previousRange = range.clone();
        int currentIndex = rangeMean(range);
        int currentNum = nums[currentIndex];

        if (target == currentNum) return currentIndex;
        else if (target > currentNum) {
            // Range should be from the next index to previous highest index
            setRange(range, currentIndex + 1, previousRange[1]);
        }
        else {
            // Range should be from previous lowest index to current highest index
            setRange(range, previousRange[0], currentIndex);

            // Covering edge case where range is first two items
            if (range[1] == 1 && range[0] == 0) range[1] = 0;
        }

        System.out.println("previousRange: " + Arrays.toString(previousRange) + " range: " + Arrays.toString(range));
        System.out.println("currentIndex: " + currentIndex + " currentNum: " + currentNum);

        // If there are no matches, an infinite loop of the same range should occur.
        // This prevents it and returns the adequate response
        if (Arrays.equals(range, previousRange)) return -1;

        return search(nums, target, range);
    }

    public static int search(int[] nums, int target) {
        int numsLength = nums.length;
        int[] range = new int[2];
        setRange(range, 0, numsLength - 1);

        // Calling overloaded method
        return search(nums, target, range);
    }

    public static void main(String[] args) {
        int[] test = {1,2,3,4,5,6,7,8};
        System.out.println(search(test, 2));
    }
}
