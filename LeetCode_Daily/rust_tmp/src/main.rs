struct Solution;

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

fn main() {
    let mut v = vec![1, 1, 2];
    let res = Solution::remove_duplicates(&mut v);
    println!("{}", res);
    println!("{:?}", v);
}
