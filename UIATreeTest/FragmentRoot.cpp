#include "UIATreeTest.h"

IFACEMETHODIMP FragmentRoot::get_HostRawElementProvider(IRawElementProviderSimple** element) {
  return UiaHostProviderFromHwnd(windowInstance, element);
}

IFACEMETHODIMP FragmentRoot::GetPatternProvider(PATTERNID pattern, IUnknown** result) {
  *result = nullptr;
  switch (pattern) {
    case UIA_TogglePatternId:
      *result = static_cast<IToggleProvider*>(this);
      break;
  }
  if (*result) {
    (*result)->AddRef();
  }
  return S_OK;
}

IFACEMETHODIMP FragmentRoot::GetPropertyValue(PROPERTYID property, VARIANT* result) {
  result->vt = VT_EMPTY;
  switch (property) {
    case UIA_NamePropertyId:
      result->vt = VT_BSTR;
      result->bstrVal = SysAllocString(L"FragmentRoot");
      break;
    case UIA_ControlTypePropertyId:
      result->vt = VT_I4;
      result->lVal = UIA_CheckBoxControlTypeId;
      break;
  }
  return S_OK;
}

IFACEMETHODIMP FragmentRoot::get_ProviderOptions(ProviderOptions* ret) {
  *ret = ProviderOptions_ServerSideProvider | ProviderOptions_UseComThreading |
         ProviderOptions_RefuseNonClientSupport |
         ProviderOptions_HasNativeIAccessible;
  return S_OK;
}

IFACEMETHODIMP FragmentRoot::ShowContextMenu() {
  return S_OK;
}

IFACEMETHODIMP FragmentRoot::Navigate(NavigateDirection dir, IRawElementProviderFragment** frag) {
  return S_OK;
}

IFACEMETHODIMP FragmentRoot::GetRuntimeId(SAFEARRAY** array) {
  SAFEARRAY* safe = SafeArrayCreateVector(VT_I4, 0, 4);
  int* data =  nullptr;
  SafeArrayAccessData(safe, reinterpret_cast<void**>(&data));
  data[0] = UiaAppendRuntimeId;
  data[1] = data[2] = 0;
  data[3] = 1; // Runtime ID
  SafeArrayUnaccessData(safe);
  *array = safe;
  return S_OK;
}

IFACEMETHODIMP FragmentRoot::get_BoundingRectangle(UiaRect* uiaRect) {
  RECT rect, crect;
  GetWindowRect(windowInstance, &rect);
  GetClientRect(windowInstance, &crect);
  POINT topLeft = {crect.left, crect.top};
  ClientToScreen(windowInstance, &topLeft);
  uiaRect->left = topLeft.x;
  uiaRect->width = crect.right - crect.left;
  uiaRect->top = topLeft.y;
  uiaRect->height = crect.bottom - crect.top;
  return S_OK;
}

IFACEMETHODIMP FragmentRoot::GetEmbeddedFragmentRoots(SAFEARRAY** roots) {
  *roots = nullptr;
  return S_OK;
}

IFACEMETHODIMP FragmentRoot::SetFocus() {
  return S_OK;
}

IFACEMETHODIMP FragmentRoot::get_FragmentRoot(IRawElementProviderFragmentRoot** root) {
  //QueryInterface(IID_PPV_ARGS(root));
  *root = nullptr;
  return UIA_E_ELEMENTNOTAVAILABLE;
}

IFACEMETHODIMP FragmentRoot::ElementProviderFromPoint(double x, double y, IRawElementProviderFragment** element) {
  QueryInterface(IID_PPV_ARGS(element));
  return S_OK;
}

IFACEMETHODIMP FragmentRoot::GetFocus(IRawElementProviderFragment** element) {
  QueryInterface(IID_PPV_ARGS(element));
  return S_OK;
}

IFACEMETHODIMP FragmentRoot::get_ToggleState(ToggleState* pRetVal) {
  *pRetVal = ToggleState_Indeterminate;
  return S_OK;
}

IFACEMETHODIMP FragmentRoot::Toggle() {
  return S_OK;
}

FragmentRoot::FragmentRoot() {}

FragmentRoot::~FragmentRoot() {}

// static
STDMETHODIMP FragmentRoot::InternalQueryInterface(void* this_ptr, const _ATL_INTMAP_ENTRY* map, REFIID riid, void** object) {
  FragmentRoot* thiz = reinterpret_cast<FragmentRoot*>(this_ptr);
  return CComObjectRootBase::InternalQueryInterface(thiz, map, riid, object);
}

// static
FragmentRoot* FragmentRoot::Create() {
  CComObject<FragmentRoot>* inst = nullptr;
  CComObject<FragmentRoot>::CreateInstance(&inst);
  inst->AddRef();
  return inst;
}
