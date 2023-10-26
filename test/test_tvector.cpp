#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(3);
	a = b;
	ASSERT_NO_THROW(TDynamicVector<int> a(b));
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
    ADD_FAILURE();
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> a(10);
	ASSERT_ANY_THROW(a.at(-5) = 5);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> a(10);
	ASSERT_ANY_THROW(a.at(34) = 5);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> a(10);

	ASSERT_NO_THROW(a = a);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> a(10);
	TDynamicVector<int> b(10);

	ASSERT_NO_THROW(a = b);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
  ADD_FAILURE();
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> a(10);
	TDynamicVector<int> b(19);

	ASSERT_NO_THROW(a = b);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	int mas[5] = {1, 2, 3, 4, 5};
	int mas1[5] = {1, 2, 3, 4, 5};
	TDynamicVector<int> a(mas1, 5);
	TDynamicVector<int> b(mas, 5);
	EXPECT_TRUE(a == b);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> a(10);
	EXPECT_TRUE(a == a);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> a(6);
	TDynamicVector<int> b(5);
	EXPECT_FALSE(a == b);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	int mas[5] = { 1, 2, 3, 4, 5 };
	int mas1[5] = { 3, 4, 5, 6, 7 };
	TDynamicVector<int> b(mas, 5);
	TDynamicVector<int> a(mas1, 5);
	EXPECT_EQ(a, b + 2);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	int mas[5] = { 1, 2, 3, 4, 5 };
	int mas1[5] = { -1, 0, 1, 2, 3 };
	TDynamicVector<int> b(mas, 5);
	TDynamicVector<int> a(mas1, 5);
	EXPECT_EQ(a, b - 2);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	int mas[5] = { 1, 2, 3, 4, 5 };
	int mas1[5] = { 10, 20, 30, 40, 50 };
	TDynamicVector<int> b(mas, 5);
	TDynamicVector<int> a(mas1, 5);
	EXPECT_EQ(a, b * 10);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> b(5);
	TDynamicVector<int> a(5);
	EXPECT_NO_THROW(TDynamicVector<int> c = a + b);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> b(5);
	TDynamicVector<int> a(6);
	EXPECT_ANY_THROW(TDynamicVector<int> c = a + b);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> b(5);
	TDynamicVector<int> a(5);
	EXPECT_NO_THROW(TDynamicVector<int> c = a - b);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> b(5);
	TDynamicVector<int> a(6);
	EXPECT_ANY_THROW(TDynamicVector<int> c = a - b);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> b(5);
	TDynamicVector<int> a(5);
	EXPECT_NO_THROW(TDynamicVector<int> c = a * b);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> b(5);
	TDynamicVector<int> a(6);
	EXPECT_ANY_THROW(TDynamicVector<int> c = a * b);
}

