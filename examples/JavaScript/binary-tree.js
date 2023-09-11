class Node {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }

  depth_first_values() {
    console.log(this.value);

    if (this.left) {
      this.left.depth_first_values();
    }

    if (this.right) {
      this.right.depth_first_values();
    }

    return;
  }

  breath_first_values() {
    const queue = [this];

    while (queue.length > 0) {
      const node = queue.shift();

      console.log(node.value);

      if (node.left) {
        queue.push(node.left);
      }

      if (node.right) {
        queue.push(node.right);
      }
    }
  }

  tree_includes(value) {
    if (this.value === value) {
      return true;
    }

    if (this.left && this.left.tree_includes(value)) {
      return true;
    }

    if (this.right && this.right.tree_includes(value)) {
      return true;
    }

    return false;
  }

  tree_sum() {
    let sum = this.value;

    if (this.left) {
      sum += this.left.tree_sum();
    }

    if (this.right) {
      sum += this.right.tree_sum();
    }

    return sum;
  }

  tree_min_value() {
    let min = this.value;

    if (this.left) {
      min = Math.min(min, this.left.tree_min_value());
    }

    if (this.right) {
      min = Math.min(min, this.right.tree_min_value());
    }

    return min;
  }

  max_root_to_leaf_path_sum() {
    if (!this.left && !this.right) {
      return this.value;
    }

    let max = 0;

    if (this.left) {
      max = Math.max(max, this.left.max_root_to_leaf_path_sum());
    }

    if (this.right) {
      max = Math.max(max, this.right.max_root_to_leaf_path_sum());
    }

    return this.value + max;
  }
}

const a = new Node(1);
const b = new Node(2);
const c = new Node(3);
const d = new Node(4);
const e = new Node(5);
const f = new Node(6);

a.left = b;
a.right = c;
b.left = d;
b.right = e;
c.left = f;

console.log("Node a value:", a.value);
console.log("Node b value:", a.left.value);
console.log("Node c value:", a.right.value);
console.log("Node d value:", a.left.left.value);
console.log("Node e value:", a.left.right.value);
console.log("Node f value:", a.right.left.value);

console.log("");
a.depth_first_values();

console.log("");
a.breath_first_values();

console.log("");

a.tree_includes(1)
  ? console.log("Tree includes 1")
  : console.log("Tree does not include 1");

a.tree_includes(9)
  ? console.log("Tree includes 9")
  : console.log("Tree does not include 9");

console.log("");
console.log("The tree sum is", a.tree_sum());

console.log("");
console.log("The tree min value is", a.tree_min_value());

console.log("");
console.log("The root to leaf path sum is", a.max_root_to_leaf_path_sum());
