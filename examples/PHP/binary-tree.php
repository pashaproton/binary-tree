<?php
class Node
{
    public int $value;
    public Node|null $left = null;
    public Node|null $right = null;

    public function __construct(int $value)
    {
        $this->value = $value;
    }

    public function printValue()
    {
        print("Node a value: " . $this->value . "\n");
    }

    public function depthFirstValues()
    {
        $this->printValue();

        if ($this->left) {
            $this->left->depthFirstValues();
        }

        if ($this->right) {
            $this->right->depthFirstValues();
        }
    }

    public function breathFirstValues()
    {
        $queue = [$this];

        while (count($queue) > 0) {
            $current = array_shift($queue);
            $current->printValue();

            if ($current->left) {
                array_push($queue, $current->left);
            }

            if ($current->right) {
                array_push($queue, $current->right);
            }
        }
    }

    public function treeIncludes(int $value)
    {
        if ($this->value == $value) {
            return true;
        }

        if ($this->left) {
            return $this->left->treeIncludes($value);
        }

        if ($this->right) {
            return $this->right->treeIncludes($value);
        }

        return false;
    }

    public function treeSum()
    {
        $sum = $this->value;

        if ($this->left) {
            $sum += $this->left->treeSum();
        }

        if ($this->right) {
            $sum += $this->right->treeSum();
        }

        return $sum;
    }

    public function treeMinValue()
    {
        $min = $this->value;

        if ($this->left) {
            $min = min([$min, $this->left->treeMinValue()]);
        }

        if ($this->right) {
            $min = min([$min, $this->right->treeMinValue()]);
        }

        return $min;
    }

    public function maxRootToLeafPathSum()
    {
        $leftSum = 0;
        $rightSum = 0;

        if ($this->left) {
            $leftSum = $this->left->maxRootToLeafPathSum();
        }

        if ($this->right) {
            $rightSum = $this->right->maxRootToLeafPathSum();
        }

        if ($leftSum > $rightSum) {
            return $this->value + $leftSum;
        }

        return $this->value + $rightSum;
    }
}

$a = new Node(1);
$b = new Node(2);
$c = new Node(3);
$d = new Node(4);
$e = new Node(5);
$f = new Node(6);

$a->left = $b;
$a->right = $c;
$b->left = $d;
$b->right = $e;
$c->left = $f;

$a->printValue();
$a->left->printValue();
$a->right->printValue();
$a->left->left->printValue();
$a->left->right->printValue();
$a->right->left->printValue();

print("\n");
$a->depthFirstValues();

print("\n");
$a->breathFirstValues();

print("\n");
if ($a->treeIncludes(1)) {
    print("Tree includes 1\n");
} else {
    print("Tree does not include 1\n");
}

print("\n");
if ($a->treeIncludes(9)) {
    print("Tree includes 9\n");
} else {
    print("Tree does not include 9\n");
}

print("\n");
print("The tree sum is " . $a->treeSum() . "\n");

print("\n");
print("The tree min value is " . $a->treeMinValue() . "\n");

print("\n");
print("The root to leaf path sum is " . $a->maxRootToLeafPathSum() . "\n");