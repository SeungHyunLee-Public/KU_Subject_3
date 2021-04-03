import Foundation

let c = readLine()!.split(separator: " ").map { Int($0)!}
var a = [Int](repeating: 0, count: 5)
var b = [Int](repeating: 0, count: 5)
var i = 0, j = 0, k = 0
var a_sum = 0
var b_sum = 0
var A_B = 0
let size = c.count / 2

for i in 0..<c.count
{
    if (i % 2 == 0)
    {
        a[j] = c[i]
        a_sum += a[j]
        j += 1
    }
    else
    {
        b[k] = c[i]
        b_sum += b[k]
        k += 1
    }
}

A_B = a_sum - b_sum
print("a배열의 합계: \(a_sum)\t b베열의 합계: \(b_sum)")
print("A - B = \(A_B)")
