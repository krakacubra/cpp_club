#include <vector>
#include <iostream>

void maxsum_subsequnce(std::vector<double>& sequence, double& maxSum, int& startIdx, int& endIdx)
{
    double sum = 0;
    double max = sequence[0];
    int start_idx = 0;
    int end_idx = 0;
    int zero_idx = 0;

    for (unsigned int i = 0; i < sequence.size(); i++)
    {
        sum += sequence[i];
        if (sum > max)
        {
            max = sum;
            start_idx = zero_idx;
            end_idx = i;
        }
        if (sum < 0)
        {
            sum = 0,
                zero_idx = i + 1;
        }
    }
    maxSum = max;
    startIdx = start_idx;
    endIdx = end_idx;
}

void main()
{
    std::vector<double> vec = { 1, 2, -5, 3, 2, -1, 5, -10, 3, 2 };
    double max = 0;
    int start_idx = 0;
    int end_idx = 0;

    maxsum_subsequnce(vec, max, start_idx, end_idx);
    std::cout << "vector: \n";
    for (auto item : vec)
        std::cout << item << " ";
    std::cout << std::endl << "max = " << max << std::endl
        << "start_idx = " << start_idx << std::endl
        << "end_idx = " << end_idx << std::endl;
    getchar();
}