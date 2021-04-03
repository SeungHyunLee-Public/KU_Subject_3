let a = 22
let b = 40
let c = 55

var sum = a + b + c
var ave = Double(sum) / 4.00
var max:Int
var min:Int

if (a > b) && (b > c)
{
    max = a
}
else if (b > c) && (c > a)
{
    max = b;
}
else
{
    max = c;
}

if (a < b) && (b < c)
{
    min = a
}
else if (b < c) && (c < a)
{
    min = b
}
else
{
    min = c
}
print("합계 : \(sum)")
print("평균 : \(ave)")
print("최대값 : \(max)")
print("최소값 : \(min)")
