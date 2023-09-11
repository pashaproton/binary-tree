#include <stdio.h>

class Node
{
private:
    int value;
    Node *left;
    Node *right;

public:
    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }

    int get_value()
    {
        return this->value;
    }

    void set_child(Node *child)
    {
        if (!this->left)
        {
            this->left = child;
        }
        else
        {
            this->right = child;
        }
    }

    void depth_first_values()
    {
        printf("%d\n", this->value);

        if (this->left)
        {
            this->left->depth_first_values();
        }

        if (this->right)
        {
            this->right->depth_first_values();
        }
    }

    void breath_first_values()
    {
        Node *queue[100];
        int head = 0;
        int tail = 0;

        queue[tail++] = this;

        while (head != tail)
        {
            Node *current = queue[head++];

            printf("%d\n", current->value);

            if (current->left)
            {
                queue[tail++] = current->left;
            }

            if (current->right)
            {
                queue[tail++] = current->right;
            }
        }
    }

    int tree_includes(int value)
    {
        if (this->value == value)
        {
            return 1;
        }

        if (this->left != NULL && this->right != NULL)
        {
            return this->left->tree_includes(value) || this->right->tree_includes(value);
        }

        if (this->left != NULL)
        {
            return this->left->tree_includes(value);
        }

        if (this->right != NULL)
        {
            return this->right->tree_includes(value);
        }

        return 0;
    }

    int tree_sum()
    {
        if (this->left != NULL && this->right != NULL)
        {
            return this->value + this->left->tree_sum() + this->right->tree_sum();
        }

        if (this->left != NULL)
        {
            return this->value + this->left->tree_sum();
        }

        if (this->right != NULL)
        {
            return this->value + this->right->tree_sum();
        }

        return 0;
    }

    int tree_min_value()
    {
        int min = this->value;

        if (this->left != NULL)
        {
            int left_min = this->left->tree_min_value();

            if (left_min < min)
            {
                min = left_min;
            }
        }

        if (this->right != NULL)
        {
            int right_min = this->right->tree_min_value();

            if (right_min < min)
            {
                min = right_min;
            }
        }

        return min;
    }

    int max_root_to_leaf_path_sum()
    {
        int left_sum = 0;

        if (this->left != NULL)
        {
            left_sum = this->left->max_root_to_leaf_path_sum();
        }

        int right_sum = 0;

        if (this->right != NULL)
        {
            right_sum = this->right->max_root_to_leaf_path_sum();
        }

        if (left_sum > right_sum)
        {
            return this->value + left_sum;
        }
        else
        {
            return this->value + right_sum;
        }
    }
};

int main(void)
{
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);

    a->set_child(b);
    a->set_child(c);
    b->set_child(d);
    b->set_child(e);
    c->set_child(f);

    printf("Node a value: %d\n", a->get_value());
    printf("Node b value: %d\n", b->get_value());
    printf("Node c value: %d\n", c->get_value());
    printf("Node d value: %d\n", d->get_value());
    printf("Node e value: %d\n", e->get_value());
    printf("Node f value: %d\n", f->get_value());

    printf("\n");
    a->depth_first_values();

    printf("\n");
    a->breath_first_values();

    printf("\n");
    if (a->tree_includes(1) == 1)
    {
        printf("Tree includes 1\n");
    }
    else
    {
        printf("Tree does not include 1\n");
    }

    if (a->tree_includes(9) == 1)
    {
        printf("Tree includes 9\n");
    }
    else
    {
        printf("Tree does not include 9\n");
    }

    printf("\n");
    printf("The tree sum is %d\n", a->tree_sum());

    printf("\n");
    printf("The tree min value is %d\n", a->tree_min_value());

    printf("\n");
    printf("The root to leaf path sum is %d\n", a->max_root_to_leaf_path_sum());

    return 0;
}