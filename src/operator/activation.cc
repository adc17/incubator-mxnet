/*!
 * Copyright (c) 2015 by Contributors
 * \file activation.cc
 * \brief
 * \author Bing Xu
*/

#include <mxnet/registry.h>
#include "./activation-inl.h"
#include "./mshadow_op.h"

namespace mxnet {
namespace op {
template<>
Operator *CreateActivationOp<cpu>(ActivationOpType type) {
  switch (type) {
    case kReLU: return new ActivationOp<cpu, mshadow_op::relu, mshadow_op::relu_grad>();
    case kSigmoid: return new ActivationOp<cpu, mshadow_op::sigmoid, mshadow_op::sigmoid_grad>();
    case kTanh: return new ActivationOp<cpu, mshadow_op::tanh, mshadow_op::tanh_grad>();
    default: return NULL;
  }
}

// DO_BIND_DISPATCH comes from operator_common.h
Operator *ActivationProp::CreateOperator(Context ctx) const {
  DO_BIND_DISPATCH(CreateActivationOp, type_);
}

REGISTER_OP_PROPERTY(Activation, ActivationProp);
}  // namespace op
}  // namespace mxnet

