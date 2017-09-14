\name{aline-package}
\docType{package}
\alias{aline-package}
\title{
Alignment of Phonetic Sequence Using the 'ALINE' Algorithm
}
\description{
Functions are provided to calculate the 'ALINE' Distance between cognate pairs. By default the Aline distance is returned (Downey et al. 2008). Several utility functions are provided including the ability to return the aligned character strings and the similarity score (Kondrak 1999), the ability to change feature weightings, and the ability to modify the IPA character mappings. The package includes functions for optimizing and plotting feature weights using expert alignment determiniations and a genetic algorithm. We provide an R-interface to the aline C++ algorithm originally written by G. Kondrak (1999, 2000). The package authors would like to acknowledge Greg Kondrak (\url{http://webdocs.cs.ualberta.ca/~kondrak/}) for developing the original ALINE algorithm. The base code provided here has been substantially modified from the original version to provide integration with R and to enable various user-functions. This project was funded by the National Science Foundation Cultural Anthropology Program (Grant number SBS-1030031) and the University of Maryland College of Behavioral and Social Sciences.

To cite 'alineR' in a publication please use:

  Sean S. Downey, Guowei Sun, and Peter Norquest. (2017). alineR: an R Package for Optimizing Feature-Weighted Alignments and Linguistic Distances. The R Journal 9(1):138-152.  \url{https://journal.r-project.org/archive/2017/RJ-2017-005/index.html}
}
\details{
\tabular{ll}{
Package: \tab alineR\cr
Type: \tab package\cr
Version: \tab 1.1.4\cr
Date: \tab 2017-9-12\cr
License: \tab GPL-3\cr
}
}
\author{
Sean S. Downey and Guowei Sun

Maintainer: Sean Downey (\email{downey.205@osu.edu})

Developer/Programmer: Guowei Sun (\email{gwsun@umd.edu})
}

\references{
Downey, S. S., Hallmark, B., Cox, M. P., Norquest, P., & Lansing, J. S. (2008). Computational feature-sensitive reconstruction of language relationships: Developing the ALINE distance for comparative historical linguistic reconstruction. Journal of Quantitative Linguistics, 15(4), 340-369. doi://dx.doi.org/10.1080/09296170802326681

Kondrak, G. (1999). Alignment of Phonetic Sequences. Technical Report CSRG-402. Department
of Computer Science, University of Toronto.

Kondrak, G. (2000). A new algorithm for the alignment of phonetic sequences. In Proceedings of the 1st North American Chapter of the Association for Computational Linguistics Conference.

}
\keyword{ package }
