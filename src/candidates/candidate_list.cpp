/*
 * Software License Agreement (BSD License)
 *
 *   Pose Estimation Library (PEL) - https://bitbucket.org/Tabjones/pose-estimation-library
 *   Copyright (c) 2014-2015, Federico Spinelli (fspinelli@gmail.com)
 *   All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of copyright holder(s) nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <pel/candidates/candidate_list.h>
#include <algorithm>
#include <pcl/console/parse.h>

using namespace pcl::console;

namespace pel
{
  std::vector<Candidate>
  CandidateLists::getCandidateList (ListType type) const
  {
    if (type == ListType::vfh)
      return vfh_list;
    else if (type == ListType::esf)
      return esf_list;
    else if (type == ListType::cvfh)
      return cvfh_list;
    else if (type == ListType::ourcvfh)
      return ourcvfh_list;
    else if (type == ListType::composite)
      return composite_list;
    else
    {
      print_error("%*s]\tListType provided not supported\n",20,__func__);
      return std::vector<Candidate>();
    }
  }
  void
  CandidateLists::printCandidateList (ListType type) const
  {
    if (type == ListType::vfh)
    {
      print_info("%*s]\tList of Candidates based on VFH:\n",20,__func__);
      for (const auto& x: vfh_list)
      {
        print_value("%-15g",x.getRank());
        print_info(" %-15s ",x.getName().c_str());
      }
    }
  }
  bool
  CandidateLists::sortListByRMSE (ListType type)
  {
    if (type == ListType::vfh && !vfh_list.empty() )
      std::sort(vfh_list.begin(), vfh_list.end(),
        [](Candidate const& a, Candidate const &b)
        {
          return (a.getRMSE() < b.getRMSE());
        } );
    else if (type == ListType::esf && !esf_list.empty())
      std::sort(esf_list.begin(), esf_list.end(),
        [](Candidate const& a, Candidate const &b)
        {
          return (a.getRMSE() < b.getRMSE());
        } );
    else if (type == ListType::cvfh && !cvfh_list.empty())
      std::sort(cvfh_list.begin(), cvfh_list.end(),
        [](Candidate const& a, Candidate const &b)
        {
          return (a.getRMSE() < b.getRMSE());
        } );
    else if (type == ListType::ourcvfh && !ourcvfh_list.empty())
      std::sort(ourcvfh_list.begin(), ourcvfh_list.end(),
        [](Candidate const& a, Candidate const &b)
        {
          return (a.getRMSE() < b.getRMSE());
        } );
    else if (type == ListType::composite && !composite_list.empty())
      std::sort(composite_list.begin(), composite_list.end(),
        [](Candidate const& a, Candidate const &b)
        {
          return (a.getRMSE() < b.getRMSE());
        } );
    else
    {
      print_error("%*s]\tListType provided not supported\n",20,__func__);
      return false;
    }
    return true;
  }
  bool
  CandidateLists::sortListByRMSE(std::vector<Candidate>& list)
  {
    if (!list.empty())
    {
      std::sort(list.begin(), list.end(),
        [](Candidate const& a, Candidate const& b)
        {
          return (a.getRMSE() < b.getRMSE());
        } );
      return (true);
    }
    else
      return (false);
  }
  bool
  CandidateLists::sortListByDistance (ListType type)
  {
    if (type == ListType::vfh && !vfh_list.empty() )
      std::sort(vfh_list.begin(), vfh_list.end(),
        [](Candidate const& a, Candidate const &b)
        {
          return (a.getDistance() < b.getDistance());
        } );
    else if (type == ListType::esf && !esf_list.empty())
      std::sort(esf_list.begin(), esf_list.end(),
        [](Candidate const& a, Candidate const &b)
        {
          return (a.getDistance() < b.getDistance());
        } );
    else if (type == ListType::cvfh && !cvfh_list.empty())
      std::sort(cvfh_list.begin(), cvfh_list.end(),
        [](Candidate const& a, Candidate const &b)
        {
          return (a.getDistance() < b.getDistance());
        } );
    else if (type == ListType::ourcvfh && !ourcvfh_list.empty())
      std::sort(ourcvfh_list.begin(), ourcvfh_list.end(),
        [](Candidate const& a, Candidate const &b)
        {
          return (a.getDistance() < b.getDistance());
        } );
    else if (type == ListType::composite && !composite_list.empty())
      std::sort(composite_list.begin(), composite_list.end(),
        [](Candidate const& a, Candidate const &b)
        {
          return (a.getDistance() < b.getDistance());
        } );
    else
    {
      print_error("%*s]\tListType provided not supported\n",20,__func__);
      return false;
    }
    return true;
  }
  bool
  CandidateLists::sortListByDistance (std::vector<Candidate>& list)
  {
    if (!list.empty())
    {
      std::sort(list.begin(), list.end(),
        [](Candidate const& a, Candidate const& b)
        {
          return (a.getDistance() < b.getDistance());
        } );
      return (true);
    }
    else
      return (false);
  }
  bool
  CandidateLists::sortListByNormalizedDistance (ListType type)
  {
    if (type == ListType::vfh && !vfh_list.empty() )
      std::sort(vfh_list.begin(), vfh_list.end(),
        [](Candidate const& a, Candidate const &b)
        {
          return (a.getNormalizedDistance() < b.getNormalizedDistance());
        } );
    else if (type == ListType::esf && !esf_list.empty())
      std::sort(esf_list.begin(), esf_list.end(),
        [](Candidate const& a, Candidate const &b)
        {
          return (a.getNormalizedDistance() < b.getNormalizedDistance());
        } );
    else if (type == ListType::cvfh && !cvfh_list.empty())
      std::sort(cvfh_list.begin(), cvfh_list.end(),
        [](Candidate const& a, Candidate const &b)
        {
          return (a.getNormalizedDistance() < b.getNormalizedDistance());
        } );
    else if (type == ListType::ourcvfh && !ourcvfh_list.empty())
      std::sort(ourcvfh_list.begin(), ourcvfh_list.end(),
        [](Candidate const& a, Candidate const &b)
        {
          return (a.getNormalizedDistance() < b.getNormalizedDistance());
        } );
    else if (type == ListType::composite && !composite_list.empty())
      std::sort(composite_list.begin(), composite_list.end(),
        [](Candidate const& a, Candidate const &b)
        {
          return (a.getNormalizedDistance() < b.getNormalizedDistance());
        } );
    else
    {
      print_error("%*s]\tListType provided not supported\n",20,__func__);
      return false;
    }
    return true;
  }
  bool
  CandidateLists::sortListByNormalizedDistance (std::vector<Candidate>& list)
  {
    if (!list.empty())
    {
      std::sort(list.begin(), list.end(),
        [](Candidate const& a, Candidate const& b)
        {
          return (a.getNormalizedDistance() < b.getNormalizedDistance());
        } );
      return (true);
    }
    else
      return (false);
  }
  bool
  CandidateLists::findAndEraseCandidate(std::vector<Candidate>& list, std::string name, float dist)
  {
    if (!list.empty())
    {
      for (std::vector<Candidate>::iterator it=list.begin(); it!=list.end(); ++it)
      {
        if (name.compare(it->getName()) ==0)
        {
          dist = it->getNormalizedDistance();
          list.erase(it);
          return true;
        }
      }
    }
    return false;
  }
}
