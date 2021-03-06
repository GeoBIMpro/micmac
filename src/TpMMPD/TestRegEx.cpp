/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/
#include "StdAfx.h"




//----------------------------------------------------------------------------
int TestRegEx_main(int argc,char ** argv)
{
    std::string aFullPattern;//pattern of all files
    bool aDispPatt=false;
    string aExport;
    
    ElInitArgMain
    (
    argc,argv,
    //mandatory arguments
    LArgMain()  << EAMC(aFullPattern, "Pattern of files",  eSAM_IsPatFile),
    
    //optional arguments
    LArgMain()  << EAM(aDispPatt, "DispPat", false, "Display Pattern to use in cmd line ; Def=false", eSAM_IsBool)
                << EAM(aExport, "ExpList", false, "Export list image in text file ; Def=false")

  
    );
    
    if (MMVisualMode) return EXIT_SUCCESS;
    
    // Initialize name manipulator & files
    std::string aDirImages,aPatIm;
    SplitDirAndFile(aDirImages,aPatIm,aFullPattern);
    std::cout<<"Working dir: "<<aDirImages<<std::endl;
    std::cout<<"Files pattern: "<<aPatIm<<std::endl;

    ofstream aExpListImg;

    if (EAMIsInit(&aExport))
    {
        aExpListImg.open (aExport.c_str());
    }


    cInterfChantierNameManipulateur * aICNM=cInterfChantierNameManipulateur::BasicAlloc(aDirImages);
    const std::vector<std::string> aSetIm = *(aICNM->Get(aPatIm));
    
    std::vector<std::string> aVIm;
    
    std::cout<<"Selected files:"<<std::endl;
    for (unsigned int i=0;i<aSetIm.size();i++)
    {
        std::cout<<" - "<<aSetIm[i]<<std::endl;
        if (EAMIsInit(&aExport))
        {
           aExpListImg<<aSetIm[i]<<endl;
        }
        aVIm.push_back(aSetIm[i]);
    }
    std::cout<<"Total: "<<aSetIm.size()<<" files."<<std::endl;
	
	if(aDispPatt)
	{
		std::string aPat="";
		
		for(unsigned int i=0;i<aVIm.size()-1;i++)
		{
			aPat = aPat + aVIm.at(i) + "|";
		}
		
		aPat = aPat + aVIm.at(aVIm.size()-1);
		
		std::cout << "Pat = \"" << aPat << "\"" << std::endl;
	}
    return EXIT_SUCCESS;
}

//----------------------------------------------------------------------------
int PatFromOri_main(int argc,char ** argv)
{
	std::string aOri;
	bool aShow=false;
	 
	ElInitArgMain
    (
    argc,argv,
    //mandatory arguments
	LArgMain()  << EAMC(aOri, "Ori Folder", eSAM_IsExistDirOri),
	
	LArgMain()  << EAM(aShow, "Show", false, "Display Pattern to use in cmd line ; Def=false",eSAM_IsBool)
	);
	
	if (MMVisualMode) return EXIT_SUCCESS;
	
	std::string aFullName="Orientation-*.*xml";
    cInterfChantierNameManipulateur *ManC=cInterfChantierNameManipulateur::BasicAlloc(aOri);
    std::list<std::string> aFiles=ManC->StdGetListOfFile(aFullName);
    
    std::vector<std::string> aNameIm;
    
    for(std::list<std::string>::iterator I=aFiles.begin();I!=aFiles.end();I++)
    {	
        std::cout << " - " << *I << std::endl;
        aNameIm.push_back(I->substr(12,I->size()-16));
    }
    std::cout<<"Total: "<<aNameIm.size()<<" files."<<std::endl;
    
    std::string aPat="";
    
    for(unsigned int i=0;i<aNameIm.size()-1;i++)
	{
		aPat = aPat + aNameIm.at(i) + "|";
	}
		
	aPat = aPat + aNameIm.at(aNameIm.size()-1);
	
	if(aShow)
		std::cout << "Pat = \"" << aPat << "\"" << std::endl;
    
    
    return EXIT_SUCCESS;
}

//----------------------------------------------------------------------------
//to add : toutes les pairs possibles (en option)
int GenFilePairs_main(int argc,char ** argv)
{
    std::string aImg, aFullPat, aOut="NameCple.xml";
	
	ElInitArgMain
    (
    argc,argv,
    //mandatory arguments
    LArgMain()  << EAMC(aImg, "Image Name or Pattern")
                << EAMC(aFullPat, "Pattern of Images", eSAM_IsPatFile),
                
    //optional arguments
    LArgMain()  << EAM(aOut, "Out", false, "Output .xml file ; Def=NameCple.xml")
  
    );
    
    if (MMVisualMode) return EXIT_SUCCESS;
    
    // Initialize name manipulator & files
    std::string aDirImages1,aPatIm1, aDirImages2,aPatIm2;
    
    SplitDirAndFile(aDirImages1,aPatIm1,aImg);
    SplitDirAndFile(aDirImages2,aPatIm2,aFullPat);
    
    std::cout<<"Working dir 1: "<<aDirImages1<<std::endl;
    std::cout<<"Working dir 2: "<<aDirImages2<<std::endl;
    
    std::cout<<"Image/Pat 1:"<<aPatIm1<<std::endl;
    std::cout<<"Images pattern 2: "<<aPatIm2<<std::endl;
    
    cInterfChantierNameManipulateur * aICNM1=cInterfChantierNameManipulateur::BasicAlloc(aDirImages1);
    cInterfChantierNameManipulateur * aICNM2=cInterfChantierNameManipulateur::BasicAlloc(aDirImages2);
    
    const std::vector<std::string> aSetIm1 = *(aICNM1->Get(aPatIm1));
    const std::vector<std::string> aSetIm2 = *(aICNM2->Get(aPatIm2));
    
    cSauvegardeNamedRel  aRelIm;
    
    for(unsigned i=0; i<aSetIm1.size(); i++)
    {
		for(unsigned j=0; j<aSetIm2.size(); j++)
		{
			cCpleString aCpl(aSetIm1.at(i),aSetIm2.at(j));
			aRelIm.Cple().push_back(aCpl);
		}
	}
    
      MakeFileXML(aRelIm,aDirImages1+aOut);
	
	return EXIT_SUCCESS;
}
/******************************************************/

//----------------------------------------------------------------------------
int CleanPatByOri_main(int argc,char ** argv)
{
	std::string aFullName, aOri, aDir, aPat, aOut;
	bool aShow=false;
	 
	ElInitArgMain
    (
    argc,argv,
    //mandatory arguments
	LArgMain()  << EAMC(aFullName,"Full Name (Dir+Pat)")
				<< EAMC(aOri, "Ori Folder", eSAM_IsExistDirOri),
	
	LArgMain()  << EAM(aShow, "Show", false, "Display Pattern to use in cmd line ; Def=false",eSAM_IsBool)
				<< EAM(aOut, "Out", false, "Output Folder Name for Images NOT will be used")
	);
	
	if (MMVisualMode) return EXIT_SUCCESS;
	
	MakeFileDirCompl(aOri);
    ELISE_ASSERT(ELISE_fp::IsDirectory(aOri),"ERROR: Input orientation not found!");

    SplitDirAndFile(aDir, aPat, aFullName);

    cInterfChantierNameManipulateur *aICNM = cInterfChantierNameManipulateur::BasicAlloc(aDir);
    std::list<std::string> aLFilePat = aICNM->StdGetListOfFile(aPat);
     
     
	std::string aFullPatOri="Orientation-*.*xml";
    cInterfChantierNameManipulateur *ManC=cInterfChantierNameManipulateur::BasicAlloc(aOri);
    std::list<std::string> aLFilesOri=ManC->StdGetListOfFile(aFullPatOri);
    
    std::vector<std::string> aNameImOri;
    
    for(std::list<std::string>::iterator I=aLFilesOri.begin();I!=aLFilesOri.end();I++)
    {	
        //std::cout << " - " << *I << std::endl;
        aNameImOri.push_back(I->substr(12,I->size()-16));
    }
    
    std::cout<<"Total images "<<aOri<<" : "<<aNameImOri.size()<<" files."<<std::endl;
    std::cout<<"Total images input Pattern: "<<aLFilePat.size()<<" files."<<std::endl;
    
    std::vector<std::string> aVImgsTrash;
    
    for(std::list<std::string>::iterator iT=aLFilePat.begin(); iT!=aLFilePat.end(); iT++)
    {
		unsigned int aCmpt=0;
		for (unsigned aP=0; aP<aNameImOri.size(); aP++)
		{
			if(iT->compare(aNameImOri.at(aP)) == 0)
				break;
				
			aCmpt++;
		}
		
		if(aCmpt == aNameImOri.size())
		{
			std::cout << "IMG PAT : " << *iT << " NOT IN ORI " << std::endl;
			aVImgsTrash.push_back(*iT);
		}
		
	}
	std::cout<<"Total images NOT OK: "<<aVImgsTrash.size()<<" files."<<std::endl;
	
	if(aOut == "")
	{
		aOut="TRASH";
	}
	
	if(aVImgsTrash.size() > 0)
	{
		ELISE_fp::MkDirSvp(aOut);
		for (unsigned aK=0; aK<aVImgsTrash.size(); aK++)
		{
			ELISE_fp::MvFile(aVImgsTrash.at(aK),aOut);
		}
	}

	
	return EXIT_SUCCESS;
}

//----------------------------------------------------------------------------
int RedImgsByN_main(int argc,char** argv)
{
	std::string aFullName, aDir, aPat, aOut="Selected_Images";
	int aPas;
	bool aShow=false;
	
	ElInitArgMain
    (
    argc,argv,
    //mandatory arguments
	LArgMain()  << EAMC(aFullName,"Full Name (Dir+Pat)")
				<< EAMC(aPas,"1/Pas"),
	LArgMain()  << EAM(aShow, "Show", false, "Display Pattern to use in cmd line ; Def=false",eSAM_IsBool)
				<< EAM(aOut, "Out", false, "Output Folder Name for Images that will be used ; Def=Selected_Images")
	);
	
	if (MMVisualMode) return EXIT_SUCCESS;
	
	//check if Output folder is not existing create it
	ELISE_fp::MkDirSvp(aOut);

    SplitDirAndFile(aDir, aPat, aFullName);

    cInterfChantierNameManipulateur *aICNM = cInterfChantierNameManipulateur::BasicAlloc(aDir);
    const std::vector<std::string> aSetIm = *(aICNM->Get(aPat));
    
    for (unsigned int aP=0; aP<aSetIm.size(); aP=aP+aPas)
    {
		ELISE_fp::CpFile(aSetIm.at(aP),aOut);
	}
	
	return EXIT_SUCCESS;
}

//----------------------------------------------------------------------------
int MvImgsByFile_main(int argc,char** argv)
{
	std::string aDir="";
	std::string aFile=""; //Schnaps_poubelle.txt (format)
	bool aShow=false;
	std::string aTrashName="Poubelle";
	
	ElInitArgMain
    (
    argc,argv,
    //mandatory arguments
	LArgMain()  << EAMC(aDir,"Directory")
				<< EAMC(aFile,"File with images names by line"),
	LArgMain()  << EAM(aShow, "Show", false, "Display Pattern to use in cmd line ; Def=false",eSAM_IsBool)
	);
	
	if (MMVisualMode) return EXIT_SUCCESS;
	
	ELISE_fp::MkDirSvp(aTrashName);
	
	//read input file
    ifstream aFichier((aDir + aFile).c_str());

    if(aFichier)
    {
		std::string aLine;
        
        while(!aFichier.eof())
        {
			getline(aFichier,aLine);
			if(!aLine.empty())
			{
				ELISE_fp::MvFile(aLine,aTrashName);
				std::cout << " Move image : " << aLine << "--> " << aTrashName << std::endl;
			}
		}
	aFichier.close();
	}
	else
    {
		std::cout<< "Error While opening file" << '\n';
	}
	
	return EXIT_SUCCESS;
}

//----------------------------------------------------------------------------
//CAM, QIHLLeeeccC, TimeUS,GPSTime,GPSWeek,Lat,Lng,Alt,RelAlt,GPSAlt,Roll,Pitch,Yaw
//CAM, 1260919656, 220518000, 1954, 48.8444203, 1.4597241, 158.37, 68.20, 158.16, 5.10, -2.80, 243.96
struct CAM{
	double TimeUS;
	double GPSTime;
	int GPSWeek;
	double Lat;
	double Lng;
	double Alt;
	double RelAlt;
	double GPSAlt;
	double Roll;
	double Pitch;
	double Yaw;
};
//GPS, QBIHBcLLefffB, TimeUS,Status,GMS,GWk,NSats,HDop,Lat,Lng,Alt,Spd,GCrs,VZ,U
//GPS, 1180441285, 3, 220437600, 1954, 12, 0.91, 48.843854, 1.459903, 94.56, 0.027, 0, 0.004, 0
//GPS2,1260807688, 6, 220518000, 1954, 12, 0.94, 48.8444246,1.4597341, 158.16, 3.331549, 243.3775, -0.6531352, 1
struct GPS{
	double TimeUS;
	int Status;
	double GMS;
	int GWk;
	int NSats;
	double HDop;
	double Lat;
	double Lng;
	double Alt;
	double Spd;
	int GCrs;
	double VZ;
	float U;
};
//POS, QLLfff, TimeUS,Lat,Lng,Alt,RelHomeAlt,RelOriginAlt
//POS, 1180414380, 48.8438484, 1.4598758, 90.17, 0.006674996, 0.656675
struct POS{
	double TimeUS;
	double Lat;
	double Lon;
	double Alt;
	double RHAlt;
	double ROAlt;
};

int GetInfosMPLF_main(int argc,char ** argv)
{
	std::string aDir="";
	std::string aFile=""; //Mission Planner .log file
	bool aShow=false;
	
	ElInitArgMain
    (
    argc,argv,
    //mandatory arguments
	LArgMain()  << EAMC(aDir,"Directory")
				<< EAMC(aFile,"Log File of Mission Planner"),
	LArgMain()  << EAM(aShow, "Show", false, "Display Pattern to use in cmd line ; Def=false",eSAM_IsBool)
	);
	
	if (MMVisualMode) return EXIT_SUCCESS;
	
	std::vector<CAM> aVCAM;
	std::vector<GPS> aVGPS;
	std::vector<GPS> aVGPS2;
	std::vector<POS> aVPos;
	
	//read input file
    ifstream aFichier((aDir + aFile).c_str());

    if(aFichier)
    {
		std::string aLine;
        
        while(!aFichier.eof())
        {
			getline(aFichier,aLine);
			
			if(!aLine.empty())
			{
				//CAM, 1260919656, 220518000, 1954, 48.8444203, 1.4597241, 158.37, 68.20, 158.16, 5.10, -2.80, 243.96
				if(aLine.compare(0,4,"CAM,") == 0)						
				{
					char *aBuffer = strdup((char*)aLine.c_str());
					std::string aType = strtok(aBuffer," ");
					std::string aTimeUS = strtok( NULL, " " );
					std::string aGpsTime = strtok( NULL, " " );
					std::string aGpsWeek = strtok( NULL, " " );
					std::string aLat = strtok( NULL, " " );
					std::string aLon = strtok( NULL, " " );
					std::string aAlt = strtok( NULL, " " );
					std::string aRelAlt = strtok( NULL, " " );
					std::string aGpsAlt = strtok( NULL, " " );
					std::string aRoll = strtok( NULL, " " );
					std::string aPitch = strtok( NULL, " " );
					std::string aYaw = strtok( NULL, " " );
					
					CAM aCamInfo;
					aCamInfo.TimeUS = atof(aTimeUS.substr(0,aTimeUS.size()-1).c_str());
					aCamInfo.GPSTime = atof(aGpsTime.substr(0,aGpsTime.size()-1).c_str());
					aCamInfo.GPSWeek = atoi(aGpsWeek.substr(0,aGpsWeek.size()-1).c_str());
					aCamInfo.Lat = atof(aLat.substr(0,aLat.size()-1).c_str());
					aCamInfo.Lng = atof(aLon.substr(0,aLon.size()-1).c_str());
					aCamInfo.Alt = atof(aAlt.substr(0,aAlt.size()-1).c_str());
					aCamInfo.RelAlt = atof(aRelAlt.substr(0,aRelAlt.size()-1).c_str());
					aCamInfo.GPSAlt = atof(aGpsAlt.substr(0,aGpsAlt.size()-1).c_str());
					aCamInfo.Roll = atof(aRoll.substr(0,aRoll.size()-1).c_str());
					aCamInfo.Pitch = atof(aPitch.substr(0,aPitch.size()-1).c_str());
					aCamInfo.Yaw = atof(aYaw.substr(0,aYaw.size()-1).c_str());
					
					aVCAM.push_back(aCamInfo);
					
				
				}
				
				//GPS, 1180441285, 3, 220437600, 1954, 12, 0.91, 48.843854, 1.459903, 94.56, 0.027, 0, 0.004, 0
				if(aLine.compare(0,4,"GPS,") == 0)						
				{
					std::cout << "aLine = " << aLine << std::endl;
					char *aBuffer = strdup((char*)aLine.c_str());
					std::string aType = strtok(aBuffer," ");
					std::string aTimeUS = strtok(aBuffer," ");
					std::string aStatus = strtok(aBuffer," ");
					std::string aGpsMilliSec = strtok(aBuffer," ");
					std::string aGpsWeek = strtok(aBuffer," ");
					std::string aNbrSat = strtok(aBuffer," ");
					std::string aHdop = strtok(aBuffer," ");
					std::string aLat = strtok( NULL, " " );
					std::string aLon = strtok( NULL, " " );
					std::string aAlt = strtok( NULL, " " );
					std::string aSpeed = strtok( NULL, " " );
					std::string aGcrs = strtok( NULL, " " );
					std::string aVZ = strtok( NULL, " " );
					std::string aU = strtok( NULL, " " );
					
					GPS aGPSInfo;
					aGPSInfo.TimeUS = atof(aTimeUS.substr(0,aTimeUS.size()-1).c_str());
					aGPSInfo.Status = atoi(aStatus.substr(0,aStatus.size()-1).c_str());
					aGPSInfo.GMS = atof(aGpsMilliSec.substr(0,aGpsMilliSec.size()-1).c_str());
					aGPSInfo.GWk = atoi(aGpsWeek.substr(0,aGpsWeek.size()-1).c_str());
					aGPSInfo.NSats = atoi(aNbrSat.substr(0,aNbrSat.size()-1).c_str());
					aGPSInfo.HDop = atof(aHdop.substr(0,aHdop.size()-1).c_str());
					aGPSInfo.Lat = atof(aLat.substr(0,aLat.size()-1).c_str());
					aGPSInfo.Lng = atof(aLon.substr(0,aLon.size()-1).c_str());
					aGPSInfo.Alt = atof(aAlt.substr(0,aAlt.size()-1).c_str());
					aGPSInfo.Spd = atof(aSpeed.substr(0,aSpeed.size()-1).c_str());
					aGPSInfo.GCrs = atoi(aGcrs.substr(0,aGcrs.size()-1).c_str());
					aGPSInfo.VZ = atof(aVZ.substr(0,aVZ.size()-1).c_str());
					aGPSInfo.U = atof(aU.substr(0,aU.size()-1).c_str());
					
					aVGPS.push_back(aGPSInfo);
					
				}
				
				//~ //GPS2,1260807688, 6, 220518000, 1954, 12, 0.94, 48.8444246,1.4597341, 158.16, 3.331549, 243.3775, -0.6531352, 1
				//~ if(aLine.compare(0,5,"GPS2,") == 0)						
				//~ {
					//~ char *aBuffer = strdup((char*)aLine.c_str());
					//~ std::string aType = strtok(aBuffer," ");
					//~ std::string aTimeUS = strtok(aBuffer," ");
					//~ std::string aStatus = strtok(aBuffer," ");
					//~ std::string aGpsMilliSec = strtok(aBuffer," ");
					//~ std::string aGpsWeek = strtok(aBuffer," ");
					//~ std::string aNbrSat = strtok(aBuffer," ");
					//~ std::string aHdop = strtok(aBuffer," ");
					//~ std::string aLat = strtok( NULL, " " );
					//~ std::string aLon = strtok( NULL, " " );
					//~ std::string aAlt = strtok( NULL, " " );
					//~ std::string aSpeed = strtok( NULL, " " );
					//~ std::string aGcrs = strtok( NULL, " " );
					//~ std::string aVZ = strtok( NULL, " " );
					//~ std::string aU = strtok( NULL, " " );
					
					//~ GPS aGPS2Info;
					//~ aGPS2Info.TimeUS = atof(aTimeUS.substr(0,aTimeUS.size()-1).c_str());
					//~ aGPS2Info.Status = atoi(aStatus.substr(0,aStatus.size()-1).c_str());
					//~ aGPS2Info.GMS = atof(aGpsMilliSec.substr(0,aGpsMilliSec.size()-1).c_str());
					//~ aGPS2Info.GWk = atoi(aGpsWeek.substr(0,aGpsWeek.size()-1).c_str());
					//~ aGPS2Info.NSats = atoi(aNbrSat.substr(0,aNbrSat.size()-1).c_str());
					//~ aGPS2Info.HDop = atof(aHdop.substr(0,aHdop.size()-1).c_str());
					//~ aGPS2Info.Lat = atof(aLat.substr(0,aLat.size()-1).c_str());
					//~ aGPS2Info.Lng = atof(aLon.substr(0,aLon.size()-1).c_str());
					//~ aGPS2Info.Alt = atof(aAlt.substr(0,aAlt.size()-1).c_str());
					//~ aGPS2Info.Spd = atof(aSpeed.substr(0,aSpeed.size()-1).c_str());
					//~ aGPS2Info.GCrs = atoi(aGcrs.substr(0,aGcrs.size()-1).c_str());
					//~ aGPS2Info.VZ = atof(aVZ.substr(0,aVZ.size()-1).c_str());
					//~ aGPS2Info.U = atof(aU.substr(0,aU.size()-1).c_str());
					
					//~ aVGPS2.push_back(aGPS2Info);
				//~ }
				
				//~ //POS, 1180414380, 48.8438484, 1.4598758, 90.17, 0.006674996, 0.656675
				//~ if(aLine.compare(0,4,"POS,") == 0)
				//~ {
					//~ char *aBuffer = strdup((char*)aLine.c_str());
					//~ std::string aType = strtok(aBuffer," ");
					//~ std::string aTimeUS = strtok(aBuffer," ");
					//~ std::string aLat = strtok(aBuffer," ");
					//~ std::string aLon = strtok(aBuffer," ");
					//~ std::string aAlt = strtok(aBuffer," ");
					//~ std::string aRHAlt = strtok(aBuffer," ");
					//~ std::string aROAlt = strtok(aBuffer," ");
					
					//~ POS aPosInfo;
					//~ aPosInfo.TimeUS = atof(aTimeUS.substr(0,aTimeUS.size()-1).c_str());
					//~ aPosInfo.Lat = atof(aLat.substr(0,aLat.size()-1).c_str());
					//~ aPosInfo.Lon = atof(aLon.substr(0,aLon.size()-1).c_str());
					//~ aPosInfo.Alt = atof(aAlt.substr(0,aAlt.size()-1).c_str());
					//~ aPosInfo.RHAlt = atof(aRHAlt.substr(0,aRHAlt.size()-1).c_str());
					//~ aPosInfo.ROAlt = atof(aROAlt.substr(0,aROAlt.size()-1).c_str());
					
					//~ aVPos.push_back(aPosInfo);
					
				//~ }
				
			}
		}
		
	aFichier.close();
	
	}
	
	else
    {
		std::cout<< "Error While opening file" << '\n';
	}
	
	std::cout << "Number of CAM Infos = " << aVCAM.size() << std::endl; 
	std::cout << "Number of GPS Infos = " << aVGPS.size() << std::endl; 
	//~ std::cout << "Number of GPS2 Infos = " << aVGPS2.size() << std::endl; 
	//~ std::cout << "Number of POS Infos = " << aVPos.size() << std::endl; 
	
	return EXIT_SUCCESS;
}

//----------------------------------------------------------------------------
class cTestElParseDir : public ElActionParseDir
{
    public :
        void act(const ElResParseDir & aRPD) 
        {
            //std::cout << aRPD.name() << "\n";
        }
};

int TestElParseDir_main(int argc,char ** argv)
{
     //cTestElParseDir aTPD;
     //ElParseDir("/home/marc/TMP/EPI/Croco/",aTPD,1000);

     return EXIT_SUCCESS;
}


/* Footer-MicMac-eLiSe-25/06/2007

Ce logiciel est un programme informatique servant �  la mise en
correspondances d'images pour la reconstruction du relief.

Ce logiciel est régi par la licence CeCILL-B soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL-B telle que diffusée par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  �  l'utilisation,  �  la modification et/ou au
développement et �  la reproduction du logiciel par l'utilisateur étant
donné sa spécificité de logiciel libre, qui peut le rendre complexe �
manipuler et qui le réserve donc �  des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités �  charger  et  tester  l'adéquation  du
logiciel �  leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement,
�  l'utiliser et l'exploiter dans les mêmes conditions de sécurité.

Le fait que vous puissiez accéder �  cet en-tête signifie que vous avez
pris connaissance de la licence CeCILL-B, et que vous en avez accepté les
termes.
Footer-MicMac-eLiSe-25/06/2007/*/
