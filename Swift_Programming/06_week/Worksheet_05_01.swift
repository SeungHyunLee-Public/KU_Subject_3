import  Foundation

let input = readLine()!.split(separator: " ").map {Int($0)! }
var sum = 0
var odd = 0
var even = 0


for i in 0..<input.count
{
    sum += input[i]
    if (input[i] % 2 == 1)
    {
        odd += input[i]
    }
    else if (input[i] % 2 == 0)
    {
        even += input[i]
    }
}

print("전체 수의 합계: \(sum)")
print("홀수의 합계   : \(odd)")
print("짝수의 합계   : \(even)")
