# What's Segment Tree :
### A segment tree is a data structure that supports two operations: processing a range query and updating an array value
 ### so that both operations work in O(log n) time.
# Hint on Size of segement tree Array
### If the size of the array is not a power of two, we can always append extra elements to it.
# Finding subsegments with the maximal sum :
### This time we will store four values for each vertex: 
### [ the sum of the segment, the maximum prefix sum, the maximum suffix sum, and the sum of the maximal subsegment in it ]
## -the answer of the left child, which means that the optimal subsegment is entirely placed in the segment of the left child
 ## -the answer of the right child, which means that the optimal subsegment is entirely placed in the segment of the right child
## -the sum of the maximum suffix sum of the left child and the maximum prefix sum of the right child, which means that the optimal subsegment intersects with both children.


# https://www.youtube.com/watch?v=ZBHKZF5w4YU&t=1396s
# https://cp-algorithms.com/data_structures/segment_tree.html