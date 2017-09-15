/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (c) 2012 Vmware, Inc.  All rights reserved.
 *  -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppDoc". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#ifndef CMethodDoc_h_
#define CMethodDoc_h_

namespace Caf {

/// Definition of a method on a class
class CMethodDoc {
public:
	CMethodDoc() :
		_isInitialized(false) {}
	virtual ~CMethodDoc() {}

public:
	/// Initializes the object with everything required by this
	/// container. Once initialized, this object cannot
	/// be changed (i.e. it is immutable).
	void initialize(
		const std::string name,
		const std::deque<SmartPtrCMethodParameterDoc> parameterCollection = std::deque<SmartPtrCMethodParameterDoc>(),
		const std::deque<SmartPtrCInstanceParameterDoc> instanceParameterCollection = std::deque<SmartPtrCInstanceParameterDoc>(),
		const std::deque<SmartPtrCClassIdentifierDoc> returnValCollection = std::deque<SmartPtrCClassIdentifierDoc>(),
		const std::deque<SmartPtrCClassIdentifierDoc> eventValCollection = std::deque<SmartPtrCClassIdentifierDoc>(),
		const std::deque<SmartPtrCClassIdentifierDoc> errorCollection = std::deque<SmartPtrCClassIdentifierDoc>(),
		const std::string displayName = std::string(),
		const std::string description = std::string()) {
		if (! _isInitialized) {
			_name = name;
			_parameterCollection = parameterCollection;
			_instanceParameterCollection = instanceParameterCollection;
			_returnValCollection = returnValCollection;
			_eventValCollection = eventValCollection;
			_errorCollection = errorCollection;
			_displayName = displayName;
			_description = description;

			_isInitialized = true;
		}
	}

public:
	/// name of the method
	std::string getName() const {
		return _name;
	}

	/// Definition of a parameter that passes simple types to the method
	std::deque<SmartPtrCMethodParameterDoc> getParameterCollection() const {
		return _parameterCollection;
	}

	/// Definition of a parameter that passes data class instances to the method
	std::deque<SmartPtrCInstanceParameterDoc> getInstanceParameterCollection() const {
		return _instanceParameterCollection;
	}

	/// Accessor for the ReturnVal
	std::deque<SmartPtrCClassIdentifierDoc> getReturnValCollection() const {
		return _returnValCollection;
	}

	/// Accessor for the EventVal
	std::deque<SmartPtrCClassIdentifierDoc> getEventValCollection() const {
		return _eventValCollection;
	}

	/// A class that may be returned to indicate an error occurred during the processing of the collection method
	std::deque<SmartPtrCClassIdentifierDoc> getErrorCollection() const {
		return _errorCollection;
	}

	/// Human-readable version of the method name
	std::string getDisplayName() const {
		return _displayName;
	}

	/// A short phrase describing the purpose of the method
	std::string getDescription() const {
		return _description;
	}

private:
	bool _isInitialized;

	std::string _name;
	std::deque<SmartPtrCMethodParameterDoc> _parameterCollection;
	std::deque<SmartPtrCInstanceParameterDoc> _instanceParameterCollection;
	std::deque<SmartPtrCClassIdentifierDoc> _returnValCollection;
	std::deque<SmartPtrCClassIdentifierDoc> _eventValCollection;
	std::deque<SmartPtrCClassIdentifierDoc> _errorCollection;
	std::string _displayName;
	std::string _description;

private:
	CAF_CM_DECLARE_NOCOPY(CMethodDoc);
};

CAF_DECLARE_SMART_POINTER(CMethodDoc);

}

#endif