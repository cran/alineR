\name{aline-package}
\docType{package}
\alias{aline-package}
\title{
Alignment of Phonetic Sequence Using the 'ALINE' Algorithm
}
\description{
Functions are provided to calculate the 'ALINE' Distance between cognate pairs. By default the aline distance is returned (Downey et al. 2008). Several utility functions are provided including the ability to return the aligned character strings and the similarity score (Kondrak 1999), the ability to change feature weightings, and the ability to modify the IPA character mappings. The package includes functions for optimizing and plotting feature weights using expert alignment determiniations and a genetic algorithm. We provide an R-interface to the aline C++ algorithm originally written by G. Kondrak (1999, 2000). The package authors would like to acknowledge Greg Kondrak (\url{http://webdocs.cs.ualberta.ca/~kondrak/}) for developing the original ALINE algorithm. The base code provided here has been substantially modified from the original version to provide integration with R and to enable various user-functions. This project was funded by the National Science Foundation Cultural Anthropology Program (Grant number SBS-1030031) and the University of Maryland College of Behavioral and Social Sciences.
}
\details{
\tabular{ll}{
Package: \tab alineR\cr
Type: \tab package\cr
Version: \tab 1.0\cr
Date: \tab 2015-7-1\cr
License: \tab GPL-3\cr
}
}
\author{
Sean S. Downey and Guowei Sun (\url{http://terpconnect.umd.edu/~sdowney2/})

Maintainer: Sean Downey (\email{sdowney2@umd.edu})

Developer/Programmer: Guowei Sun (\email{gwsun@umd.edu})
}

\references{
Downey, S. S., Hallmark, B., Cox, M. P., Norquest, P., & Lansing, J. S. (2008). Computational feature-sensitive reconstruction of language relationships: Developing the ALINE distance for comparative historical linguistic reconstruction. Journal of Quantitative Linguistics, 15(4), 340-369.

Kondrak, G. (1999). Alignment of Phonetic Sequences. Technical Report CSRG-402. Department
of Computer Science, University of Toronto.

Kondrak, G. (2000). A new algorithm for the alignment of phonetic sequences. In Proceedings of the 1st North American Chapter of the Association for Computational Linguistics Conference.

}
\keyword{ package }
