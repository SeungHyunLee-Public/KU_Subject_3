import Foundation

var a : [Int] = [38, 97, 25, 66, 90, 31, 16, 86, 33, 59]
var even_sum = 0, odd_sum = 0, i = 0
var even_count : Double = 0
var odd_count : Double = 0
var even_ave : Double = 0
var odd_ave : Double = 0

for i in 0..<a.count
{

    if (a[i] % 2 == 0)
    {
        even_sum += a[i]
        even_count += 1
    }
    else
    {
        odd_sum += a[i]
        odd_count += 1
    }
}

even_ave = Double(even_sum) / Double(even_count)
odd_ave = Double(odd_sum) / Double(odd_count)

print("짝수의 합: \(even_sum)\t 평균: \(even_ave)")
print("홀수의 합: \(odd_sum)\t 평균: \(odd_ave)") 
