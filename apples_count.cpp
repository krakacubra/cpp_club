#include <vector>
#include <iostream>

std::vector<int> max_count_second(const int n_children, const int n_in_frame, std::vector<int> apples_per_child)
{
    std::vector<int> answere;
    int max_i = 0;
    int start = 0;

    for (int i = 0; i < n_in_frame; ++i)
        if (apples_per_child[max_i] < apples_per_child[i])
            max_i = i;

    answere.push_back(apples_per_child[max_i]);

    for (int i = n_in_frame; i < n_children; ++i)
    {
        start++;
        if (max_i >= start && apples_per_child[i] > apples_per_child[max_i])
            max_i = i;
        if (max_i < start)
            for (int j = start; j < start + n_in_frame; ++j)
                if (apples_per_child[max_i] < apples_per_child[j])
                    max_i = j;

        answere.push_back(apples_per_child[max_i]);
    }
    return answere;
}

void main()
{
    char to_continue = 'n';
    size_t n_children = 0;
    int n_in_frame = 0;

    while (true)
    {
        std::vector<int> apples_per_child = {};
        std::cout << "input: \nn_children n_in_frame" << std::endl;
        std::cin >> n_children;
        std::cin >> n_in_frame;
        std::cout << std::endl << "apples per child" << std::endl;
        size_t i = 0;
        int tmp = 0;
        while (i < n_children)
        {
            std::cin >> tmp;
            apples_per_child.push_back(tmp);
            i++;
        }

        std::vector<int> ans = max_count_second(n_children, n_in_frame, apples_per_child);
        std::cout << "answere: ";
        for (int i = 0; i < ans.size(); ++i)
        {
            std::cout << ans[i] << " ";
        }
        std::cout << "would you like to continue? (y/n)";
        std::cin >> to_continue;
    }
}