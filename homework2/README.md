作业2
1. 考虑n皇后问题，其解空间树为由1、2、…、n构成的n!种排列所组成。现用回溯法求解，要求：
（1）通过解搜索空间说明n=3时是无解的。
（2）给出剪枝操作。
（3）最坏情况下在解空间树上会生成多少个结点？分析算法的时间复杂度。

2. 设计一个算法求解简单装载问题，设有一批集装箱要装上一艘载重量为W的轮船，其中编号为i（0≤i≤n-1）的集装箱的重量为wi。现要从n个集装箱中选出若干装上轮船，使它们的重量之和正好为W。如果找到任一种解返回true，否则返回false。

3. 给定若干个正整数a0、a0 、…、an-1 ，从中选出若干数，使它们的和恰好为k，要求找选择元素个数最少的解。 

4. 设计求解有重复元素的排列问题的算法，设有n个元素a[]={a0，a1，…，an-1)，其中可能含有重复的元素，求这些元素的所有不同排列。如a[]={1，1，2}，输出结果是（1，1，2)，（1，2，1），（2，1，1）。

5. 采用递归回溯法设计一个算法求1～n的n个整数中取出m个元素的排列，要求每个元素最多只能取一次。例如，n=3，m=2的输出结果是（1，2），（1，3），（2，1），（2，3），（3，1），（3，2）。
