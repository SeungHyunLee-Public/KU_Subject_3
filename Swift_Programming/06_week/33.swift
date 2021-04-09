print("정수 10개를 입력하시오.")

var evennum = 0
var oddnum = 0

var array = [Int](repeating: 0, count: 10)

for _ in 0 ..< array.count {
  let number = readLine()!
  let num = Int(number)
  if num % 2 == 0 {
    evennum += num
  }
  else {
    oddnum += num
  }
}

print("짝수의 합 : \(evennum)")
print("홀수의 합 : \(oddnum)")
print("전체 수의 합 : \(oddnum + evennum)")
