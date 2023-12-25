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
	TDynamicVector<int> v(11);
	for (int i = 0; i < 11; i++) {
		v[i] = i;
	}
	TDynamicVector<int> k(v);
	EXPECT_EQ(v, k);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v(11);
	for (int i = 0; i < 11; i++) {
		v[i] = i;
	}
	TDynamicVector<int> k(v);
	for (int i = 0; i < 11; i++) {
		v[i] += i;
	}
	EXPECT_NE(v, k);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(11);
	ASSERT_ANY_THROW(v.at(-1));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(11);
	ASSERT_ANY_THROW(v.at(12));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(11);
	ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(11);
	EXPECT_EQ(k.size(), v.size());
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(11);
	ASSERT_NO_THROW(v = k);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(12);
	EXPECT_NE(k.size(), v.size());
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(v);
	EXPECT_EQ(true, k == v);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v(11);
	EXPECT_EQ(true, v == v);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(12);
	EXPECT_NE(k.size(), v.size());
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v(11);
	ASSERT_NO_THROW(v + 11);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v(11);
	ASSERT_NO_THROW(v - 7);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> v(11);
	ASSERT_NO_THROW(v * 7);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(11);
	ASSERT_NO_THROW(v + k);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(12);
	ASSERT_ANY_THROW(v + k);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(11);
	ASSERT_NO_THROW(v - k);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(12);
	ASSERT_ANY_THROW(v - k);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(11);
	ASSERT_NO_THROW(v * k);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(12);
	ASSERT_ANY_THROW(v * k);
}

