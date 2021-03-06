/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (C) 2012-2016 VMware, Inc.  All rights reserved. -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"

#include "Doc/DocXml/CafCoreTypesXml/AttachmentNameCollectionXml.h"

#include "Doc/CafCoreTypesDoc/CAttachmentNameCollectionDoc.h"
#include "Doc/CafInstallRequestDoc/CPackageDefnDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/CafInstallRequestXml/PackageDefnXml.h"

using namespace Caf;

void PackageDefnXml::add(
	const SmartPtrCPackageDefnDoc packageDefnDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("PackageDefnXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(packageDefnDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string startupAttachmentNameVal = packageDefnDoc->getStartupAttachmentName();
		CAF_CM_VALIDATE_STRING(startupAttachmentNameVal);
		thisXml->addAttribute("startupAttachmentName", startupAttachmentNameVal);

		const std::string packageAttachmentNameVal = packageDefnDoc->getPackageAttachmentName();
		CAF_CM_VALIDATE_STRING(packageAttachmentNameVal);
		thisXml->addAttribute("packageAttachmentName", packageAttachmentNameVal);

		const SmartPtrCAttachmentNameCollectionDoc supportingAttachmentNameCollectionVal =
			packageDefnDoc->getSupportingAttachmentNameCollection();
		if (! supportingAttachmentNameCollectionVal.IsNull()) {
			const SmartPtrCXmlElement supportingAttachmentNameCollectionXml =
				thisXml->createAndAddElement("attachmentNameCollection");
			AttachmentNameCollectionXml::add(supportingAttachmentNameCollectionVal, supportingAttachmentNameCollectionXml);
		}

		const std::string argumentsVal = packageDefnDoc->getArguments();
		if (! argumentsVal.empty()) {
			thisXml->addAttribute("arguments", argumentsVal);
		}
	}
	CAF_CM_EXIT;
}

SmartPtrCPackageDefnDoc PackageDefnXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("PackageDefnXml", "parse");

	SmartPtrCPackageDefnDoc packageDefnDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string startupAttachmentNameStrVal =
			thisXml->findRequiredAttribute("startupAttachmentName");
		const std::string startupAttachmentNameVal = startupAttachmentNameStrVal;

		const std::string packageAttachmentNameStrVal =
			thisXml->findRequiredAttribute("packageAttachmentName");
		const std::string packageAttachmentNameVal = packageAttachmentNameStrVal;

		const SmartPtrCXmlElement supportingAttachmentNameCollectionXml =
			thisXml->findOptionalChild("attachmentNameCollection");

		SmartPtrCAttachmentNameCollectionDoc supportingAttachmentNameCollectionVal;
		if (! supportingAttachmentNameCollectionXml.IsNull()) {
			supportingAttachmentNameCollectionVal = AttachmentNameCollectionXml::parse(supportingAttachmentNameCollectionXml);
		}

		const std::string argumentsStrVal =
			thisXml->findOptionalAttribute("arguments");
		const std::string argumentsVal = argumentsStrVal;

		packageDefnDoc.CreateInstance();
		packageDefnDoc->initialize(
			startupAttachmentNameVal,
			packageAttachmentNameVal,
			supportingAttachmentNameCollectionVal,
			argumentsVal);
	}
	CAF_CM_EXIT;

	return packageDefnDoc;
}

