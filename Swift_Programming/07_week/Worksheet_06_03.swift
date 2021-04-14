func Calculate(_ A: Int, _ B: Int)
{
    func add(_ A: Int,_ B: Int) 
{
        print("A + B = \(A + B)")
    }
    func sub(_ A: Int, _ B: Int) 
{
        print("A - B = \(A - B)")
    }
    func mul(_ A: Int, _ B: Int) 
{
        print("A * B = \(A * B)")
    }
    func div(_ A: Int, _ B: Int) {
        print("A / B = \(A / B)")
    }    
    add(A, B)
    sub(A, B)
    mul(A, B)
    div(A, B)
}
print("숫자를 입력하세요")
var c = Int(readLine()!)
var d = Int(readLine()!)
 
Calculate(c!, d!)
