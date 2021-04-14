func worksheet06(_ A: Int, _ B: Int) -> (A: Int ,B: Int)
{
    let div = A / B
    let mod = A % B
    return (div,mod)
}
 print("숫자를 입력하세요")
var div = Int(readLine()!)
var mod = Int(readLine()!)
 
var result = worksheet06(div!,mod!)
print(result)
