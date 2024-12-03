import { open } from "node:fs/promises";

const input = await open("day01.txt");
const nums1 = [];
const nums2 = [];
for await (const line of input.readLines()) {
    const [n1, n2] = line.split(/ +/);
    nums1.push(Number.parseInt(n1, 10));
    nums2.push(Number.parseInt(n2, 10));
}
nums1.sort((a, b) => a - b);
nums2.sort((a, b) => a - b);

let sum = 0;
for (let i = 0; i < nums1.length; i++) {
    sum += Math.abs(nums1[i] - nums2[i]);
}
console.log(sum);
