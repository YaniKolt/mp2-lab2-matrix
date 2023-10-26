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

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v.at(5));
}

TEST(TDynamicVector, check_ravno)
{
	TDynamicVector<int> v(4);
	TDynamicVector<int> v1(4);
	int i;
	for (i = 0; i < 4; i++) {
		v[i] = 0;
		v1[i] = 0;
	}
	ASSERT_ANY_THROW(v = v1);
}

TEST(TDynamicVector, negative_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v.at(-1));
}

TEST(TDynamicVector, check_pluse)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> v1(4);
	int i;
	for (i = 0; i < 4; i++) {
		v[i] = 0;
		v1[i] = 0;
	}
	ASSERT_ANY_THROW(v + v1);
}

TEST(TDynamicVector, check_minus)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> v1(4);
	int i;
	for (i = 0; i < 4; i++) {
		v[i] = 0;
		v1[i] = 0;
	}
	ASSERT_ANY_THROW(v - v1);
}
TEST(TDynamicVector, check_minus_da)
{
	TDynamicVector<int> v(4);
	TDynamicVector<int> v1(4);
	int i;
	for (i = 0; i < 4; i++) {
		v[i] = 0;
		v1[i] = 0;
	}
	ASSERT_NO_THROW(v - v1);
}

TEST(TDynamicVector, check_pluse_da)
{
	TDynamicVector<int> v(4);
	TDynamicVector<int> v1(4);
	int i;
	for (i = 0; i < 4; i++) {
		v[i] = 0;
		v1[i] = 0;
	}
	ASSERT_NO_THROW(v + v1);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v(4);
	TDynamicVector<int> v1(4);
	int i;
	for (i = 0; i < 4; i++) {
		v[i] = 0;
		v1[i] = 1;
	}
	v = v + 1;
	int a = 0;
	if (v == v1)a = 1;
	EXPECT_EQ(a, 1);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v(4);
	TDynamicVector<int> v1(4);
	int i;
	for (i = 0; i < 4; i++) {
		v[i] = 0;
		v1[i] = 1;
	}
	v1 = v1 - 1;
	int a = 0;
	if (v == v1)a = 1;
	EXPECT_EQ(a, 1);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> v(4);
	TDynamicVector<int> v1(4);
	int i;
	for (i = 0; i < 4; i++) {
		v[i] = 1;
		v1[i] = 2;
	}
	v = v * 2;
	int a = 0;
	if (v == v1)a = 1;
	EXPECT_EQ(a, 1);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v(4);
	TDynamicVector<int> v1(4);
	int i;
	for (i = 0; i < 4; i++) {
		v[i] = 0;
		v1[i] = 0;
	}
	ASSERT_NO_THROW(v * v1);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v(5);
	TDynamicVector<int> v1(4);
	int i;
	for (i = 0; i < 4; i++) {
		v1[i] = 0;
	}
	for (i = 0; i < 5; i++) {
		v[i] = 0;
	}
	ASSERT_ANY_THROW(v1 * v);
}