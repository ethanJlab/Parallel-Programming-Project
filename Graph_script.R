df0 <- read.csv("fib_memo.csv", sep = ",")
plot(df0,type="l",main="Fib w/ Matrix Method w/ Multi-Threading", xlab="Number of Digits Generated", ylab= "Time (sec)")





plot(df1, type="l", main = "Naive vs Naive Multi-Threaded", xlab="Number of Digits Generated", ylab= "Time (sec)")
lines(df0)
lines(df0, col = "red")

matrix_mt<- read.csv("matrix_multi_threaded" ,sep = ",")
plot(matrix_mt, type="l", main = "Matrix Multi-Threaded", xlab="Number of Digits Generated", ylab= "Time (nanoseconds)")

matrix_mt<- read.csv("matrix_memo_matrix" ,sep = ",")
matrix_mt<-matrix_mt[ order(matrix_mt$Num),]
plot(matrix_mt, type='l', main = "Matrix Memo", xlab="Number of Digits Generated", ylab= "Time (nanoseconds)")



