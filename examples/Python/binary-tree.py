class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value

    def depth_first_values(self) -> None:
        print("Node value:", self.value)

        if (self.left != None):
            self.left.depth_first_values()

        if (self.right != None):
            self.right.depth_first_values()

    def breath_first_values(self) -> None:
        queue = [self]

        while (len(queue) > 0):
            current = queue.pop(0)

            print("Node value:", current.value)

            if (current.left != None):
                queue.append(current.left)
            
            if (current.right != None):
                queue.append(current.right)

    def tree_includes(self, value) -> bool:
        if (self.value == value):
            return True
        
        if (self.left == None and self.right == None):
            return False
        
        if (self.left == None):
            return self.right.tree_includes(value)
        
        if (self.right == None):
            return self.left.tree_includes(value)

        return self.left.tree_includes(value) or self.right.tree_includes(value)

    def tree_sum(self) -> int:
        sum = self.value

        if (self.left != None):
            sum += self.left.tree_sum()
        
        if (self.right != None):
            sum += self.right.tree_sum()
        
        return sum

    def tree_min_value(self) -> int:
        min_value = self.value

        if (self.left != None):
            min_value = min(min_value, self.left.tree_min_value())
        
        if (self.right != None):
            min_value = min(min_value, self.right.tree_min_value())
        
        return min_value

    def max_root_to_leaf_path_sum(self) -> int:
        if (self.left == None and self.right == None):
            return self.value
        
        if (self.left == None):
            return self.value + self.right.max_root_to_leaf_path_sum()
        
        if (self.right == None):
            return self.value + self.left.max_root_to_leaf_path_sum()
        
        return self.value + max(self.left.max_root_to_leaf_path_sum(), self.right.max_root_to_leaf_path_sum())


a = Node(1)
b = Node(2)
c = Node(3)
d = Node(4)
e = Node(5)
f = Node(6)

a.left = b
a.right = c
b.left = d
b.right = e
c.left = f

print("Node a value:", a.value)
print("Node b value:", a.left.value)
print("Node c value:", a.right.value)
print("Node d value:", a.left.left.value)
print("Node e value:", a.left.right.value)
print("Node f value:", a.right.left.value)

print("")
a.depth_first_values()

print("")
a.breath_first_values()

print("")
if (a.tree_includes(1) == 1):
    print("Tree includes 1")
else:
    print("Tree does not include 1")

if (a.tree_includes(9) == 1):
    print("Tree includes 9")
else:
    print("Tree does not include 9")

print("")
print("The tree sum is", a.tree_sum())

print("")
print("The tree min value is", a.tree_min_value())

print("")
print("The root to leaf path sum is", a.max_root_to_leaf_path_sum())