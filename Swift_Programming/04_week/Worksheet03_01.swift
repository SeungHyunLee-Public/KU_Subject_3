import Foundation

var str = "This is string test program"

print("변경 전 문자열 : \(str)")
str = str.replacingOccurrences(of: " ", with: "")
print("변경 후 문자열 : \(str)")
