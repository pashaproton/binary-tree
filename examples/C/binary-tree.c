#include <stdio.h>

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

void depth_first_values(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("Node value: %d\n", node->value);
    depth_first_values(node->left);
    depth_first_values(node->right);
}

void breath_first_values(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }

    struct Node *queue[100];
    int head = 0;
    int tail = 0;

    queue[tail++] = node;

    while (head != tail)
    {
        struct Node *current = queue[head++];

        printf("Node value: %d\n", current->value);

        if (current->left != NULL)
        {
            queue[tail++] = current->left;
        }

        if (current->right != NULL)
        {
            queue[tail++] = current->right;
        }
    }
}

int tree_includes(struct Node *node, int value)
{
    if (node == NULL)
    {
        return 0;
    }

    if (node->value == value)
    {
        return 1;
    }

    return tree_includes(node->left, value) || tree_includes(node->right, value);
}

int tree_sum(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return node->value + tree_sum(node->left) + tree_sum(node->right);
}

int tree_min_value(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int min = node->value;

    if (node->left != NULL)
    {
        int left_min = tree_min_value(node->left);

        if (left_min < min)
        {
            min = left_min;
        }
    }

    if (node->right != NULL)
    {
        int right_min = tree_min_value(node->right);

        if (right_min < min)
        {
            min = right_min;
        }
    }

    return min;
}

int max_root_to_leaf_path_sum(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int left_sum = max_root_to_leaf_path_sum(node->left);
    int right_sum = max_root_to_leaf_path_sum(node->right);

    if (left_sum > right_sum)
    {
        return node->value + left_sum;
    }
    else
    {
        return node->value + right_sum;
    }
}

int main(void)
{
    struct Node a = {1, NULL, NULL};
    struct Node b = {2, NULL, NULL};
    struct Node c = {3, NULL, NULL};
    struct Node d = {4, NULL, NULL};
    struct Node e = {5, NULL, NULL};
    struct Node f = {6, NULL, NULL};

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;

    printf("Node a value: %d\n", a.value);
    printf("Node b value: %d\n", a.left->value);
    printf("Node c value: %d\n", a.right->value);
    printf("Node d value: %d\n", a.left->left->value);
    printf("Node e value: %d\n", a.left->right->value);
    printf("Node f value: %d\n", a.right->left->value);

    printf("\n");
    depth_first_values(&a);

    printf("\n");
    breath_first_values(&a);

    printf("\n");
    if (tree_includes(&a, 1) == 1)
    {
        printf("Tree includes 1\n");
    }
    else
    {
        printf("Tree does not include 1\n");
    }

    if (tree_includes(&a, 9) == 1)
    {
        printf("Tree includes 9\n");
    }
    else
    {
        printf("Tree does not include 9\n");
    }

    printf("\n");
    printf("The tree sum is %d\n", tree_sum(&a));

    printf("\n");
    printf("The tree min value is %d\n", tree_min_value(&a));

    printf("\n");
    printf("The root to leaf path sum is %d\n", max_root_to_leaf_path_sum(&a));

    return 0;
}