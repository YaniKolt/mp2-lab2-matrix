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
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> b(3);
	a = b;
	ASSERT_NO_THROW(TDynamicMatrix<int> a(b));
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> a(4);
	
	EXPECT_EQ(4, a[0].size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> v(4);
	v[0][0] = 4;

	EXPECT_EQ(4, v[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> a(10);
	ASSERT_ANY_THROW(a[0].at(-5) = 5);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> a(10);
	ASSERT_ANY_THROW(a[0].at(34) = 5);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> a(10);

	ASSERT_NO_THROW(a = a);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> a(10);
	TDynamicMatrix<int> b(10);

	ASSERT_NO_THROW(a = b);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> a(10);
	TDynamicMatrix<int> b(19);

	ASSERT_NO_THROW(a = b);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	int mas[5] = { 1, 2, 3, 4, 5 };
	int mas1[5] = { 1, 2, 3, 4, 5 };
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = (mas, 5);
	}
	TDynamicMatrix<int> b(5);
	for (int i = 0; i < 5; i++) {
		b[i] = (mas1, 5);
	}
	EXPECT_TRUE(a == b);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	int mas1[5] = { 1, 2, 3, 4, 5 };
	TDynamicMatrix<int> b(5);
	for (int i = 0; i < 5; i++) {
		b[i] = (mas1, 5);
	}
	EXPECT_TRUE(b == b);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	
	TDynamicMatrix<int> a(5);
	
	TDynamicMatrix<int> b(6);
	
	EXPECT_FALSE(a == b);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	int mas[5] = { 1, 2, 3, 4, 5 };
	int mas1[5] = { 2, 4, 6, 8, 10 };
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = (mas, 5);
	}
	TDynamicMatrix<int> b(5);
	for (int i = 0; i < 5; i++) {
		b[i] = (mas, 5);
	}
	TDynamicMatrix<int> c(5);
	for (int i = 0; i < 5; i++) {
		c[i] = (mas1, 5);
	}
	EXPECT_EQ(c, a + b);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> a(10);
	TDynamicMatrix<int> b(19);

	ASSERT_ANY_THROW(TDynamicMatrix<int> c = a + b);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	int mas[5] = { 1, 2, 3, 4, 5 };
	int mas1[5] = { 0, 0, 0, 0, 0 };
	TDynamicMatrix<int> a(5);
	for (int i = 0; i < 5; i++) {
		a[i] = (mas, 5);
	}
	TDynamicMatrix<int> b(5);
	for (int i = 0; i < 5; i++) {
		b[i] = (mas, 5);
	}
	TDynamicMatrix<int> c(5);
	for (int i = 0; i < 5; i++) {
		c[i] = (mas1, 5);
	}
	EXPECT_EQ(c, a - b);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> a(10);
	TDynamicMatrix<int> b(19);

	ASSERT_ANY_THROW(TDynamicMatrix<int> c = a - b);
}

