好的，我翻译一下这一的意思吧！其实就是告诉你两个人和一条狗各时刻的瞬时速度，让你求出两人相遇的时候狗跑了多长的距离。当然，这里的相遇只需要两人相距10m以内。这个看上去很复杂的积分题如果在你做的时候注意一些细节，那么你就可以瞬间秒杀它了。
 
我的做法是在积分的过程中，把sin(sin2t)sin(cos2t)看做一个整体，假设是间接时间x（因为两者是一一对应的）。那么，此时的两个人对其速度和的积分就只是积v=v1sin(1)/x，最后在两人相遇前，所用的间接时间x=e(l1-10)/t。
同理，对狗的速度的积分将变成v=v2cos(1)*1.55741/x，最后积得间接时间x内狗跑的距离s=v2cos(1)*1.55741*ln x。
整理可得，狗在两人相遇前最多能跑的距离为s=v2cos(1)*1.55741*(l1-10)/v1/sin1。然后就是比较数据给出狗跑的最长距离就可以得出答案了。
 
 
View Code