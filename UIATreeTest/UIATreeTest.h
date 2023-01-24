#pragma once

#include "framework.h"
#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>
#include <UIAutomation.h>

extern HWND windowInstance;

class __declspec(uuid("12344321-1234-5678-9abc-123456654321")) FragmentRoot
  : public ATL::CComObjectRootEx<CComMultiThreadModel>,
    public IRawElementProviderSimple2,
    public IRawElementProviderFragment,
    public IRawElementProviderFragmentRoot,
    public IToggleProvider {

 public:
  BEGIN_COM_MAP(FragmentRoot)
  COM_INTERFACE_ENTRY(FragmentRoot)
  COM_INTERFACE_ENTRY(IRawElementProviderSimple)
  COM_INTERFACE_ENTRY(IRawElementProviderSimple2)
  COM_INTERFACE_ENTRY(IRawElementProviderFragment)
  COM_INTERFACE_ENTRY(IRawElementProviderFragmentRoot)
  COM_INTERFACE_ENTRY(IToggleProvider)
  END_COM_MAP()

  IFACEMETHODIMP get_HostRawElementProvider(IRawElementProviderSimple**) override;

  IFACEMETHODIMP GetPatternProvider(PATTERNID , IUnknown**) override;

  IFACEMETHODIMP GetPropertyValue(PROPERTYID, VARIANT*) override;

  IFACEMETHODIMP get_ProviderOptions(ProviderOptions*) override;

  IFACEMETHODIMP ShowContextMenu() override;

  IFACEMETHODIMP Navigate(NavigateDirection, IRawElementProviderFragment**) override;

  IFACEMETHODIMP GetRuntimeId(SAFEARRAY**) override;

  IFACEMETHODIMP get_BoundingRectangle(UiaRect*) override;

  IFACEMETHODIMP GetEmbeddedFragmentRoots(SAFEARRAY**) override;

  IFACEMETHODIMP SetFocus() override;

  IFACEMETHODIMP get_FragmentRoot(IRawElementProviderFragmentRoot**) override;

  IFACEMETHODIMP ElementProviderFromPoint(double, double, IRawElementProviderFragment**) override;

  IFACEMETHODIMP GetFocus(IRawElementProviderFragment**) override;

  IFACEMETHODIMP get_ToggleState(ToggleState *pRetVal) override;

  IFACEMETHODIMP Toggle() override;

  FragmentRoot();

  virtual ~FragmentRoot();

  static STDMETHODIMP InternalQueryInterface(void*, const _ATL_INTMAP_ENTRY*, REFIID, void**);

  static FragmentRoot* Create();

};

extern FragmentRoot* root;
