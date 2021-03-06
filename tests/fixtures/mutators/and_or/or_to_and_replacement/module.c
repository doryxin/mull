#include "test_and_or_operators.h"

#include <stdio.h>

enum { SUCCESS = 0, FAILURE = 1 };

void dummy() {}

int testee_OR_operator_2branches(int a, int b, int c) {
  if (a < b || b < c) {
    printf("left branch\n");
    return a;
  } else {
    printf("right branch\n");
    return b;
  }
}

int testee_OR_operator_1branch(int a, int b, int c) {
  if (a < b || b < c) {
    printf("left branch\n");
    return a;
  }

  printf("right branch\n");
  return b;
}

/// Edge case: OR expression that always evaluates to a scalar value but also
/// contains a dummy function call (presence of a dummy function makes the
/// Branch instruction to be generated).
/// This case is based on https://github.com/mull-project/mull/issues/501.
/// The code below is based on the code generated by the csmith:
/// a() { ((b(), 9) || 9, 0) || a; }
int testee_OR_operator_always_scalars_case_with_function_call_pattern1(int A) {
  if ((((dummy(), 0) || 1), 1) || A) {
    printf("left branch\n");
    return 1;
  } else {
    printf("right branch\n");
    return 0;
  }
}

int testee_OR_operator_always_scalars_case_with_function_call_pattern3(int A) {
  if (((dummy(), 9) || 9), A) {
    return 1;
  } else {
    printf("right branch\n");
    return 0;
  }
}

int test_OR_operator_2branches() {
  if (testee_OR_operator_2branches(1, 3, 2) == 1) {
    return SUCCESS;
  }
  return FAILURE;
}

int test_OR_operator_1branch() {
  if (testee_OR_operator_1branch(1, 3, 2) == 1) {
    return SUCCESS;
  }
  return FAILURE;
}

int test_OR_operator_always_scalars_case_with_function_call_pattern1() {
  if (testee_OR_operator_always_scalars_case_with_function_call_pattern1(1) == 1) {
    return SUCCESS;
  }
  return FAILURE;
}

int test_OR_operator_always_scalars_case_with_function_call_pattern3() {
  if (testee_OR_operator_always_scalars_case_with_function_call_pattern3(1) == 1) {
    return SUCCESS;
  }
  return FAILURE;
}
