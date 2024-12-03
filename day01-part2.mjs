import { open } from "node:fs/promises";

const input = await open("day01.txt");
const nums1 = [];
const nums2 = [];
for await (const line of input.readLines()) {
    const [n1, n2] = line.split(/ +/);
    nums1.push(Number.parseInt(n1, 10));
    nums2.push(Number.parseInt(n2, 10));
}

const rightCounts = new Map();
for (const n of nums2) {
    rightCounts.set(n, (rightCounts.get(n) ?? 0) + 1);
}

let similarity = 0;
for (const n of nums1) {
    similarity += n * (rightCounts.get(n) ?? 0);
}
console.log(similarity);
