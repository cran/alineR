\name{generate.training}
\alias{generate.training}
\title{
Generate training dataset
}
\description{
Generates an output file of training data to be used by a linguist to select the best alignments from a list of the unique set of possible alignments for each given pair of words.
}
\usage{
generate.training(raw.data, search.size=1000,table=TRUE,
                  file.out="candidate_alignments.csv")
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{raw.data}{
This is a 2*n matrix containing n ipa encoded cognate pairs.
}
\item{search.size}{
Number of time to randomize feature parameters while searching for unique alignments.
}
\item{table}{
table=TRUE will generate a csv file named by the user containing possible alignments in IPA encodings.
}
\item{file.out}{
Name of CSV file for output.
}
}

\value{
A list containing two elements:
\item{standard_ipa_symbol}{A data frame containing input cognate pairs and a list of possible alignemnts. UTF-8 IPA}
\item{ALINE_symbol}{Same as above, but using ALINE symbol for use in internal funcitons}

}
\note{
Expert determinations are used by the genetic algorithm to optimize feature weights. Feature parameters are randomly generated to find possible alignments, so setting search.size to larger values will ensure all possible alignments are found.

To generate the output file set file.out to some value and open the resulting file with a spreadshet program. To ensure correct Unicode IPA formattting, make sure the file encoding is selected as UTF-8 when importing the generated csv file.

The function also returns an list containing two dataframes (IPA and Aline) that are used internally in the optimization process. 
}
\seealso{
\code{\link{optimize.features}}
}
\examples{
# some cognates
data<-data.frame(dog=c('dog','perro'),cat=c('cat','gato'),rat=c('rat','rata'))

# write out a CSV file that can be openned in Excel and used for expert determinations
M<-generate.training(raw.data=data,search.size=100,file="open.with.excel.csv")

}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ csv Table }
\keyword{ Candiate Alignments to Choose From }% __ONLY ONE__ keyword per line

