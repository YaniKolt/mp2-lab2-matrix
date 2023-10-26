#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
    ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
    TDynamicMatrix<int> m(5);

    ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
    TDynamicMatrix<int> m(1);

    ASSERT_ANY_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, can_get_size)
{
    TDynamicMatrix<int> a(5);
    EXPECT_EQ(5, a[1].size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
    TDynamicMatrix<int> a(5);
    a[1][1] = 1;

    EXPECT_EQ(1, a[1][1]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_negative_index)
{
    TDynamicMatrix<int> a(5);
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++)
        {
            a[i][j] = 1;
        }
    ASSERT_ANY_THROW(a[5].at(-1));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    ASSERT_NO_THROW(TDynamicMatrix<int> a(););
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> a(5);
    ASSERT_NO_THROW(TDynamicMatrix<int> b(a[1].size()););
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> a(5), b(5);
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++)
        {
            a[i][j] = 1;
            b[i][j] = 1;
        }
    int flag = 0;
    if (a == b)flag = 1;
    EXPECT_EQ(flag, 1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> a(5);
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++)
        {
            a[i][j] = 1;
        }
    int flag = 0;
    if (a == a)flag = 1;
    EXPECT_EQ(flag, 1);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> a(5), b(6);
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++)
        {
            a[i][j] = 1;
            b[i][j] = 2;
        }
    int flag = 0;
    if (a == b)flag = 1;
    EXPECT_EQ(flag, 0);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> a(5), b(5), c(5), d(5);
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++)
        {
            a[i][j] = 1;
            b[i][j] = 2;
            c[i][j] = 3;
        }
    d = c - b;
    int flag = 0;
    if (a == d)flag = 1;
    EXPECT_EQ(flag, 1);
}

TEST(TDynamicMatrix, cant_subtract_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> a(5), b(6);
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++)
        {
            a[i][j] = 1;
            b[i][j] = 2;
        }
    ASSERT_ANY_THROW(a - b);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int> a(5), b(5), c(5), d(5);
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++)
        {
            a[i][j] = 1;
            b[i][j] = 2;
            c[i][j] = 3;
        }
    d = a + b;
    int flag = 0;
    if (c == d)flag = 1;
    EXPECT_EQ(flag, 1);
}

TEST(TDynamicMatrix, cant_add_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> a(5), b(6);
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = i; j < 5; j++)
        {
            a[i][j] = 1;
            b[i][j] = 2;
        }
    ASSERT_ANY_THROW(a + b);
}

