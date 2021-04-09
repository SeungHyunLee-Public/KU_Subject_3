import Foundation

let input = readLine()!.split(separator: " ").map {Int($0)!}

var A = input[0] % 2  

if (input[0] == 0)
{
    print("\(input)은 짝수도 홀수도 아닙니다.")
    exit (0)
}

switch A
{
    case 0 :
        print("\(input)은 짝수입니다.")
    case 1 :
        print("\(input)는 홀수입니다.")
    default:
        print("정수가 아님")
}
