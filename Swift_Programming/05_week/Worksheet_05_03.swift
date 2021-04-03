import Foundation

var dic : [Int : String] = [111:"이순신", 222:"홍길동", 333:"강감찬", 444:"세종대왕", 555:"을지문덕"]

let a = readLine()!

if a == "0"
{
    print(dic)    
}

else if a == "111"
{
    print(dic[111]!)
}

else if a == "222"
{
    print(dic[222]!)
}

else if a == "333"
{
    print(dic[333]!)
}

else if a == "444"
{
    print(dic[444]!)
}

else if a == "555"
{
    print(dic[555]!)
}
