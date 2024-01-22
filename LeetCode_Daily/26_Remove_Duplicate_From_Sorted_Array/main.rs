struct Solution;

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        if nums.len() == 1 {
            return 0;
        }

        let mut tmp_nums = nums.clone();
        for item in 1..tmp_nums.len() {
            if tmp_nums[item] == tmp_nums[item - 1] {
                tmp_nums[item - 1] = -10005;
            }
        }

        nums.clear();

        for (_, item) in tmp_nums.iter().enumerate() {
            if *item != -10005 {
                nums.push(*item);
            }
        }
        return nums.len() as i32;
    }
}

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let len = nums.len();
        if len <= 1 {
            return len as i32;
        }
        
        let mut index = 1;
        for i in 1..len {
            if nums[i] != nums[i-1] {
                nums[index] = nums[i];
                index += 1;
            }
        }
        
        nums.truncate(index);
        index as i32
    }
}