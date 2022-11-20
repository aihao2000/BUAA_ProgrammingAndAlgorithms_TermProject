# buaa_ProgrammingAndAlgorithms_TermProject



##基础排序
### 对比图

| 排序种类\数据规模 | 1e5  | 1e6   | 1e7    | 1e8     | 1e9      |
|--------| ---- | ----- | ------ | ------- | -------- |
| 选择排序   | 33ms | 396ms | 4635ms | 53719ms | 594666ms |
| 归并排序   | 11ms | 102ms | 831ms  | 9594ms  | 104291ms |
| 简单快速排序 |      |       |        |         |          |
| 希尔排序   |      |       |        |         |          |
| 基数排序   |      |       |        |         |          |

### 基础排序算法分析

#### 简单选择排序
简单选择排序
基本思想：比较+交换
1. 从待排序序列中，找到关键字最小的元素；
2. 如果最小元素不是待排序序列的第一个元素，将其和第一个元素互换；
3. 从余下的 N - 1 个元素中，找出关键字最小的元素，重复(1)、(2)步，直到排序结束。
   简单选择排序通过两层循环实现。
   第一层循环：依次遍历序列当中的每一个元素
   第二层循环：将遍历得到的当前元素依次与余下的元素进行比较，符合最小元素的条件，则交换。

总的时间复杂度为O(n^2)


##### 归并排序




## 分布式排序

### 对比图

| 排序种类\数据规模                     | 1e5  | 1e6   | 1e7    | 1e8     | 1e9      |
| ------------------------------------- | ---- | ----- | ------ | ------- | -------- |
| 普通快速排序                          | 33ms | 396ms | 4635ms | 53719ms | 594666ms |
| 无锁分布式快速排序，基于future与async | 11ms | 102ms | 831ms  | 9594ms  | 104291ms |
|                                       |      |       |        |         |          |

### 无锁分布式快速排序

#### 实验结果

- 1e5

  ![image-20221115000222836](README.assets/image-20221115000222836.png)

- 1e6

  ![image-20221115000245982](README.assets/image-20221115000245982.png)

- 1e7

  ![image-20221114233724776](README.assets/image-20221114233724776.png)

- 1e8

  ![image-20221114234145665](README.assets/image-20221114234145665.png)

- 1e9

  ![image-20221115000051316](README.assets/image-20221115000051316.png)
